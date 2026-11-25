#pragma once

#include "SDL3/SDL_events.h"
#include "SDL3/SDL_video.h"
#include <functional>
#include <string>
namespace xse {
    struct WindowSpecification {
        std::string title;
        int width = 1280, height = 720;
        bool fullscreen = false, resizable = false;
    };

    class Window {
        using EventCallbackFunc = std::function<void(SDL_Event&)>;

        private:
            SDL_Window* m_Handle = nullptr;
            WindowSpecification m_Specification;
            EventCallbackFunc m_EventCallback;

            bool m_IsTerminated = false;

        public:
            Window(const WindowSpecification& spec) : m_Specification(spec) {}
            ~Window() {}

            void Initialize();
            void Terminate();

            void ProcessEvents();
            void SetEventCallback(const EventCallbackFunc& callback);
            EventCallbackFunc GetEventCallback();

            void SetTitle(const std::string& title);
            const std::string GetTitle();
    };
}