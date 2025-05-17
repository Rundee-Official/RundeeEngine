//Project Name: RundeeEngine
//File Name: JobSystem.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: JobSystem class header file

#pragma once
#include <functional>
#include <memory>
#include <thread>

namespace RundeeEngine
{
	class ThreadPool;

	class JobSystem
	{
	public:
		static void Initialize(size_t threadCount = std::thread::hardware_concurrency());
		static void Shutdown();

		static void Dispatch(const std::function<void()>& job);

	private:
		static std::unique_ptr<ThreadPool> s_ThreadPool;
	};
}