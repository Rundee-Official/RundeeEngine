//Project Name: Sandbox
//File Name: Sandbox.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Sandbox file to test the ThreadPool class

#include <iostream>
#include <sstream>
#include "RundeeEngine/JobSystem.h"
#include "RundeeEngine/Logger.h"

int main() {
    RundeeEngine::JobSystem::Initialize(4);

    for (int i = 0; i < 8; ++i) {
        RundeeEngine::JobSystem::Dispatch([i]() {
            std::ostringstream oss;
            oss << "[Job " << i << "] is running in thread " << std::this_thread::get_id();
            RundeeEngine::Logger::Info(oss.str());
            });
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    RundeeEngine::JobSystem::Shutdown();

	// Test Logger
    RundeeEngine::Logger::Info("Engine initialized.");
    RundeeEngine::Logger::Warning("This is a warning message.");
    RundeeEngine::Logger::Error("Something went wrong.");

    return 0;
}
