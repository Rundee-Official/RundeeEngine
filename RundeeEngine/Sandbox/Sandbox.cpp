//Project Name: Sandbox
//File Name: Sandbox.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Sandbox file to test the ThreadPool class

#include "RundeeEngine/Common/CommonType.h"
#include "RundeeEngine/Renderer/Renderer.h"
#include "RundeeEngine/Logger.h"
#include <SDL.h>

using namespace RundeeEngine;

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

        //Put Draw function here
        RundeeEngine::Renderer::DrawRect(RundeeEngine::Vec2{0, 0}, 1000, 800, 0.5f, 0.5f, 0.5f, 1.0f);

        RundeeEngine::Renderer::Present();
    }

    RundeeEngine::Renderer::Shutdown();
    return 0;
}