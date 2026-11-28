#include "Renderer.h"
#include "Math/Vector2.h"
#include "core/Window.h"
#include "SDL3/SDL_render.h"
#include <cassert>

namespace xse {
    Window* Renderer::m_Window = nullptr;
    SDL_Renderer* Renderer::m_Handle = nullptr;
    RendererConfig Renderer::m_Config{};

    void Renderer::Initialize(Window* window, const RendererConfig& config) {
        m_Handle = SDL_CreateRenderer(&window->GetHandle(), NULL);
        assert(m_Handle);

        m_Config = config;

        SDL_SetRenderLogicalPresentation(m_Handle,
            m_Config.logicalSize.x, m_Config.logicalSize.y,
            SDL_LOGICAL_PRESENTATION_LETTERBOX
        );
    }

    void Renderer::Terminate() {
        SDL_DestroyRenderer(m_Handle);
    }

    void Renderer::Present() {
        SDL_RenderPresent(m_Handle);
    }

    void Renderer::SetDrawColor(Color color) {
        SDL_SetRenderDrawColor(m_Handle,
            color.r, color.g, color.b, color.a
        );
    }

    void Renderer::SetClearColor(Color color) {
        m_Config.clearColor = color;
    }

    void Renderer::Clear() {
        SetDrawColor(m_Config.clearColor);
        SDL_RenderClear(m_Handle);
    }

    void Renderer::SetLogicalSize(Vector2 size) {
        m_Config.logicalSize = size;
        SDL_SetRenderLogicalPresentation(m_Handle, size.x, size.y, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    }

    Vector2 Renderer::GetLogicalSize() {
        return m_Config.logicalSize;
    }

    void Renderer::DrawLine(Vector2 from, Vector2 to, Color color) {
        SetDrawColor(color);
        SDL_RenderLine(m_Handle,
            from.x, from.y,
            to.x, to.y
        );
    }

    void Renderer::DrawDebug(Vector2 pos, std::string text, Color color) {
        SetDrawColor(color);
        SDL_SetRenderScale(m_Handle, 0.45, 0.45);
        SDL_RenderDebugText(m_Handle,
            pos.x, pos.y,
            text.c_str()
        );
        SDL_SetRenderScale(m_Handle, 1, 1);
    }

    void Renderer::DrawRect(Vector2 pos, Vector2 size, Color color) {
        SDL_FRect rect {
            pos.x, pos.y,
            size.x, size.y
        };
        SetDrawColor(color);
        SDL_RenderFillRect(m_Handle, &rect);
    }
}