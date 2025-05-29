//Project Name: RundeeEngine
//File Name: Renderer.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Renderer class implementation file

#include <Windows.h>
#include <glad/glad.h>
#include <SDL.h>

#include "../../include/RundeeEngine/Common/CommonType.h"
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
            1600, 900, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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

	void Renderer::DrawTriangle(Vec2 a, Vec2 b, Vec3 c)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(a.x, a.y);
        glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(b.x, b.y);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(c.x, c.y);
		glEnd();
	}

	void Renderer::DrawRect(Vec2 position, float width, float height, float r, float g, float b, float a)
	{
		glBegin(GL_QUADS);
        glColor4f(r, g, b, a);
		glVertex2f(position.x, position.y);
		glVertex2f(position.x + width, position.y);
		glVertex2f(position.x + width, position.y + height);
		glVertex2f(position.x, position.y + height);
		glEnd();
	}

	void Renderer::DrawLine(Vec2 start, Vec2 end, float r, float g, float b, float a)
	{
		glBegin(GL_LINES);
		glColor4f(r, g, b, a);
		glVertex2f(start.x, start.y);
		glVertex2f(end.x, end.y);
		glEnd();
	}

	void Renderer::DrawCircle(Vec2 center, float radius, int segments, float r, float g, float b, float a)
	{
		glBegin(GL_LINE_LOOP);
		glColor4f(r, g, b, a);
		for (int i = 0; i < segments; ++i)
		{
			float angle = 2.0f * 3.1415926f * i / segments;
			float x = center.x + cos(angle) * radius;
			float y = center.y + sin(angle) * radius;
			glVertex2f(x, y);
		}
		glEnd();
	}

	void Renderer::DrawText(const char* text, Vec2 position, float size, float r, float g, float b, float a)
	{
		// Placeholder for text rendering logic
		// This would typically involve using a library like FreeType or SDL_ttf

		Logger::Warning("DrawText is not implemented yet.");
	}

	void Renderer::SetViewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	void Renderer::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}
}