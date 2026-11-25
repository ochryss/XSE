#include "Renderer.h"
#include "core/Window.h"
#include "SDL3/SDL_render.h"
#include <cassert>

namespace xse {
    Window* Renderer::m_Window = nullptr;
    SDL_Renderer* Renderer::m_Handle = nullptr;
    Color Renderer::m_ClearColor = {40,40,40};

    void Renderer::Initialize(Window* window) {
        m_Handle = SDL_CreateRenderer(&window->GetHandle(), NULL);
        assert(m_Handle);

        SDL_SetRenderLogicalPresentation(m_Handle,
            m_LogicalSize.x, m_LogicalSize.y,
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
        m_ClearColor = color;
    }

    void Renderer::Clear() {
        SetDrawColor(m_ClearColor);
        SDL_RenderClear(m_Handle);
    }

    void Renderer::DrawLine(Vector2 from, Vector2 to) {
        SetDrawColor({255,255,255});
        SDL_RenderLine(m_Handle,
            from.x, from.y,
            to.x, to.y
        );
    }

    void Renderer::DrawDebug(Vector2 pos, std::string text) {
        SetDrawColor({255,255,255});
        SDL_SetRenderScale(m_Handle, 0.45, 0.45);
        SDL_RenderDebugText(m_Handle,
            pos.x, pos.y,
            text.c_str()
        );
        SDL_SetRenderScale(m_Handle, 1, 1);
    }

    void Renderer::DrawRect(Vector2 pos, Vector2 size) {
        SDL_FRect rect {
            pos.x, pos.y,
            size.x, size.y
        };
        SetDrawColor({255,255,255});
        SDL_RenderFillRect(m_Handle, &rect);
    }
}