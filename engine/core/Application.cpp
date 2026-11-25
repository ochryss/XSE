#include "Application.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_timer.h"
#include "Window.h"

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
            // TODO
        });
    }

    Application::~Application() {
        m_Window->Terminate();
        s_Instance = nullptr;
    }

    void Application::Initialize() {
        OnInitialization();

        float deltaTime = 0.0f,
            lastTime = SDL_GetTicks() / 1000.0f;

        while (!m_IsTerminated) {
            m_Window->ProcessEvents();

            float currentTime = SDL_GetTicks() / 1000.0f;
            deltaTime = currentTime - lastTime, lastTime = currentTime;

            // TODO(Renderer Clear)

            // TODO(Update)
            OnUpdate(deltaTime);

            // TODO(Render)
            OnRender(deltaTime);

            // TODO(Renderer Present)
        }
    }

    void Application::Terminate() {
        if (m_IsTerminated) return;
        m_IsTerminated = true;
        OnTermination();
    }

    void Application::HandleEvent() {}
}