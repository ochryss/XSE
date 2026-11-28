#pragma once
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "SDL3/SDL_render.h"
#include <string>

namespace xse {
    class Window;
    struct RendererConfig {
        Vector2 logicalSize{320, 180};
        Color clearColor{40, 40, 40};
    };

    class Renderer {
        private:
            static Window* m_Window;
            static SDL_Renderer* m_Handle;

            static RendererConfig m_Config;

            static void SetDrawColor(Color color);
        public:
            static void Initialize(Window* window, const RendererConfig& config);
            static void Terminate();

            static void Present();
            static void SetClearColor(Color color);
            static void Clear();

            static void SetLogicalSize(Vector2 size);
            static Vector2 GetLogicalSize();

            static void DrawLine(Vector2 from, Vector2 to, Color color = Colors::White);
            static void DrawDebug(Vector2 pos, std::string text, Color color = Colors::White);
            static void DrawRect(Vector2 pos, Vector2 size, Color color = Colors::White);
    };
}