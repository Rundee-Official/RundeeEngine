//Project Name: RundeeEngine
//File Name: Renderer.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Renderer class header file

#pragma once

namespace RundeeEngine {
    struct Vec2;
    struct Vec3;

    class Renderer {
    public:
        static bool Init();    
        static void Shutdown();
        static void Clear();   
        static void Present(); 

        static void DrawTriangle(Vec2 a, Vec2 b, Vec3 c);
		static void DrawRect(Vec2 position, float width, float height, float r, float g, float b, float a);
    };
}