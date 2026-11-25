#include "Application.h"
#include "Math/Vector2.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_timer.h"
#include "Window.h"
#include "graphics/Renderer.h"
#include <algorithm>

namespace xse {
    Application* Application::s_Instance = nullptr;

    Application::Application(const ApplicationSpecification& spec) : m_Specification(spec) {
        s_Instance = this;

        m_Window = new Window({
            .title = m_Specification.title,
            .width = m_Specification.windowWidth, .height = m_Specification.windowHeight,
            .fullscreen = m_Specification.fullscreen, .resizable = m_Specification.resizable
        });

        m_Window->Initialize();
        m_Window->SetEventCallback([this](SDL_Event& event) {
            HandleEvent();
        });

        Renderer::Initialize(m_Window, {
            .logicalSize = Vector2(m_Specification.logicalWidth, m_Specification.logicalHeight)
        });
    }

    Application::~Application() {
        Renderer::Terminate();
        m_Window->Terminate();
        s_Instance = nullptr;
    }

    void Application::Initialize() {
        OnInitialization();

        const double frequency = static_cast<double>(SDL_GetPerformanceFrequency());
        double lastTime = static_cast<double>(SDL_GetPerformanceCounter()) / frequency;

        while (!m_IsTerminated) {
            m_Window->ProcessEvents();
            
            const double currentTime = static_cast<double>(SDL_GetPerformanceCounter()) / frequency;
            float deltaTime = static_cast<float>(currentTime - lastTime);
            lastTime = currentTime;
            // Avoid physics malfunction on stutters/low framerate
            // Effectively freezes instead of compensating for high mspf (ms per frame)
            deltaTime = std::min(deltaTime, 1.0f / 60.0f);

            Renderer::Clear();

            // TODO(Update)
            OnUpdate(deltaTime);

            // TODO(Render)
            OnRender(deltaTime);

            Renderer::Present();
        }
    }

    void Application::Terminate() {
        if (m_IsTerminated) return;
        m_IsTerminated = true;
        OnTermination();
    }

    void Application::HandleEvent() {}
}