#pragma once
#include "SDL3/SDL_render.h"
#include <string>

namespace xse {
    // Temp
    struct Color { int r, g, b, a = 255; };
    struct Vector2 { float x, y; };

    class Window;

    class Renderer {
        private:
            static Window* m_Window;
            static SDL_Renderer* m_Handle;

            static Color m_ClearColor;

            static inline Vector2 m_LogicalSize{320, 180};

            static void SetDrawColor(Color color);
        public:
            static void Initialize(Window* window/*int logicalWidth, int logicalHeight*/);
            static void Terminate();

            static void Present();
            static void SetClearColor(Color color);
            static void Clear();

            static void DrawLine(Vector2 from, Vector2 to);
            static void DrawDebug(Vector2 pos, std::string text);
            static void DrawRect(Vector2 pos, Vector2 size);
    };
}