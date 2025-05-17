//Project Name: RundeeEngine
//File Name: Renderer.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Renderer class header file

#pragma once

namespace RundeeEngine {
    class Renderer {
    public:
        static bool Init();    
        static void Shutdown();
        static void Clear();   
        static void Present(); 
    };
}