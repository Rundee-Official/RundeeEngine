//Project Name: RundeeEngine
//File Name: ThreadPool.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: ThreadPool class header file

#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>

namespace RundeeEngine
{
    class ThreadPool 
    {
    public:
        ThreadPool(size_t numThreads);
        ~ThreadPool();

        void Enqueue(const std::function<void()>& job);

    private:
        void WorkerThread();

        std::vector<std::thread> m_Threads;
        std::queue<std::function<void()>> m_Jobs;
        std::mutex m_QueueMutex;
        std::condition_variable m_Condition;
        std::atomic<bool> m_ShouldStop;
    };
}