//Project Name: RundeeEngine
//File Name: ThreadPool.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: ThreadPool class implementation file

#include "../include/RundeeEngine/Logger.h"
#include "../include/RundeeEngine/ThreadPool.h"
#include <sstream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <thread>
#endif

namespace RundeeEngine {

    ThreadPool::ThreadPool(size_t numThreads) : m_ShouldStop(false)
    {
        try 
        {
            for (size_t i = 0; i < numThreads; ++i) 
            {
                m_Threads.emplace_back(&ThreadPool::WorkerThread, this);
            }
            Logger::Info("ThreadPool created with " + std::to_string(numThreads) + " threads.");
        }
        catch (const std::exception& e) 
        {
            Logger::Error(std::string("ThreadPool creation failed: ") + e.what());
        }
    }

    ThreadPool::~ThreadPool()
    {
        m_ShouldStop = true;
        m_Condition.notify_all();

        for (auto& thread : m_Threads) 
        {
            if (thread.joinable())
            {
                thread.join();
            }
        }

        Logger::Info("ThreadPool destroyed and all threads joined.");
    }

    void ThreadPool::Enqueue(const std::function<void()>& job)
    {
        {
            std::unique_lock<std::mutex> lock(m_QueueMutex);
            m_Jobs.push(job);
        }
        m_Condition.notify_one();
    }

    void ThreadPool::WorkerThread()
    {
        while (!m_ShouldStop) 
        {
            std::function<void()> job;

            {
                std::unique_lock<std::mutex> lock(m_QueueMutex);
                m_Condition.wait(lock, [&]() {
                    return !m_Jobs.empty() || m_ShouldStop;
                    });

                if (m_ShouldStop && m_Jobs.empty()) 
                {
                    Logger::Info("Worker thread terminating.");
                    return;
                }

                job = std::move(m_Jobs.front());
                m_Jobs.pop();
            }

            try 
            {
                std::ostringstream oss;
                #ifdef _WIN32
                oss << GetCurrentThreadId();
                #else
                oss << std::this_thread::get_id();
                #endif
                
                job();
            }
            catch (const std::exception& e) 
            {
                Logger::Error(std::string("Exception during job execution: ") + e.what());
            }
        }
    }
}