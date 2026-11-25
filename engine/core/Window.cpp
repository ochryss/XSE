#include "Window.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_init.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_video.h"
#include <cassert>

namespace xse {
    void Window::Initialize() {
        bool result = SDL_Init(SDL_INIT_VIDEO);
        assert(result);

        SDL_DisplayID primaryMonitor = SDL_GetPrimaryDisplay();
        SDL_Rect monitorRect;
        SDL_GetDisplayBounds(primaryMonitor, &monitorRect);

        if (m_Specification.fullscreen) {
            m_Specification.width = monitorRect.w;
            m_Specification.height = monitorRect.h;
        }

        m_Handle = SDL_CreateWindow(
            m_Specification.title.c_str(),
            m_Specification.width, m_Specification.height,
            0
        );
    }

    void Window::Terminate() {
        if (!m_IsTerminated) return;
        m_IsTerminated = true;
        SDL_DestroyWindow(m_Handle);
        SDL_Quit();
    }

    void Window::ProcessEvents() {
        SDL_Event event;
        SDL_PollEvent(&event);

        // TODO(Event Translation)
        GetEventCallback()(event);
    }

    void Window::SetTitle(const std::string &title) {
        m_Specification.title = title;
        SDL_SetWindowTitle(m_Handle, title.c_str());
    }

    const std::string Window::GetTitle() {
        return m_Specification.title;
    }

    void Window::SetEventCallback(const EventCallbackFunc &callback) {
        m_EventCallback = callback;
    }

    Window::EventCallbackFunc Window::GetEventCallback() {
        return m_EventCallback;
    }
}