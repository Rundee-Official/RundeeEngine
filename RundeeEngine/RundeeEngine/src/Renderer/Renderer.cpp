//Project Name: RundeeEngine
//File Name: Renderer.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Renderer class implementation file

#include "../../include/RundeeEngine/Renderer/Renderer.h"
#include "../../include/RundeeEngine/Logger.h"

#include <SDL3/SDL.h>

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

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		g_Window = SDL_CreateWindow("RundeeEngine", 1920, 1080, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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

		SDL_GL_SetSwapInterval(1);
		
		Logger::Info("Renderer initialized successfully.");
		return true;
	}

	void Renderer::Shutdown()
	{
		SDL_GL_DestroyContext(g_GLContext);
		SDL_DestroyWindow(g_Window);
		SDL_Quit();
		Logger::Info("Renderer shutdown successfully.");
	}

	void Renderer::Clear()
	{
		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::Present()
	{
		SDL_GL_SwapWindow(g_Window);
	}
}