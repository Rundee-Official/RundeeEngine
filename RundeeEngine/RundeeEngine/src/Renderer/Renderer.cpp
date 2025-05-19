//Project Name: RundeeEngine
//File Name: Renderer.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Renderer class implementation file

#include <Windows.h>
#include <glad/glad.h>
#include <SDL.h>

#include "../../include/RundeeEngine/Renderer/Renderer.h"
#include "../../include/RundeeEngine/Logger.h"

static SDL_Window* g_Window = nullptr;
static SDL_GLContext g_GLContext = nullptr;

namespace RundeeEngine
{
    bool Renderer::Init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) 
        {
            Logger::Error("SDL_Init failed: " + std::string(SDL_GetError()));
            return false;
        }

        g_Window = SDL_CreateWindow("RundeeEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
        if (!g_Window) 
        {
            Logger::Error("SDL_CreateWindow failed: " + std::string(SDL_GetError()));
            SDL_Quit();
            return false;
        }

        g_GLContext = SDL_GL_CreateContext(g_Window);
        if (!g_GLContext) 
        {
            Logger::Error("SDL_GL_CreateContext failed: " + std::string(SDL_GetError()));
            SDL_DestroyWindow(g_Window);
            SDL_Quit();
            return false;
        }

        if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) 
        {
            Logger::Error("Failed to initialize GLAD");
            return false;
        }

        SDL_GL_SetSwapInterval(1);
        Logger::Info("Renderer initialized successfully.");
        return true;
    }

    void Renderer::Shutdown()
    {
        SDL_GL_DeleteContext(g_GLContext);
        SDL_DestroyWindow(g_Window);
        SDL_Quit();
        Logger::Info("Renderer shutdown successfully.");
    }

    void Renderer::Clear()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::Present()
    {
        SDL_GL_SwapWindow(g_Window);
    }
}