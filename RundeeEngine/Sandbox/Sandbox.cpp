//Project Name: Sandbox
//File Name: Sandbox.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Sandbox file to test the ThreadPool class

#include "RundeeEngine/Renderer/Renderer.h"
#include "RundeeEngine/Logger.h"
#include <SDL.h>

int main() {
    RundeeEngine::Logger::Info("Starting RundeeEngine...");

    if (!RundeeEngine::Renderer::Init())
        return -1;

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        RundeeEngine::Renderer::Clear();
        RundeeEngine::Renderer::Present();
    }

    RundeeEngine::Renderer::Shutdown();
    return 0;
}