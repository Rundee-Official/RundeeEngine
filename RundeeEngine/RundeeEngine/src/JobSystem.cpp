//Project Name: RundeeEngine
//File Name: JobSystem.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: JobSystem class implementation file

#include "../include/RundeeEngine/Logger.h"
#include "../include/RundeeEngine/JobSystem.h"
#include "../include/RundeeEngine/ThreadPool.h"

namespace RundeeEngine 
{
	std::unique_ptr<ThreadPool> JobSystem::s_ThreadPool;

    void JobSystem::Initialize(size_t threadCount) 
    {
        if (s_ThreadPool) 
        {
            Logger::Warning("JobSystem already initialized.");
            return;
        }

        s_ThreadPool = std::make_unique<ThreadPool>(threadCount);
        Logger::Info("JobSystem initialized with " + std::to_string(threadCount) + " threads.");
    }

    void JobSystem::Shutdown() 
    {
        if (!s_ThreadPool) 
        {
            Logger::Warning("JobSystem::Shutdown() called before initialization.");
            return;
        }

        s_ThreadPool.reset();
        Logger::Info("JobSystem shutdown completed.");
    }

    void JobSystem::Dispatch(const std::function<void()>& job) {
        if (s_ThreadPool) 
        {
            s_ThreadPool->Enqueue(job);
            Logger::Info("Dispatched job to thread pool.");
        }
        else 
        {
            Logger::Error("Cannot dispatch job: ThreadPool is not initialized.");
        }
    }
}