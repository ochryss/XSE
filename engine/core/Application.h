#pragma once
#include <algorithm>
#include <string>

namespace xse {
    struct ApplicationSpecification {
        std::string title;
        int windowWidth = 1280, windowHeight = 720;
        bool resizable = false, fullscreen = false;

        int logicalWidth = 320, logicalHeight = 180;
        bool vsync = false;
    };

    class Window;
    class Event;

    class Application {
        private:
            bool m_IsTerminated = false;
            static Application* s_Instance;

            Window* m_Window = nullptr;

            ApplicationSpecification m_Specification;
            /*int*/float m_TimeScale = 1;
        public:
            Application(const ApplicationSpecification& spec);
            virtual ~Application();

            virtual void OnInitialization() {}
            virtual void OnTermination() {}
            virtual void OnUpdate(float deltaTime) {}
            virtual void OnRender(float deltaTime) {}
            virtual void OnEvent(Event& event) {}

            void Initialize();
            void Terminate();

            void HandleEvent(Event& event);

            void SetTimeScale(float timeScale) { this->m_TimeScale = std::max(timeScale, 0.0f); }
            float GetTimeScale() const { return m_TimeScale; }

            inline Window& GetWindow() const { return *m_Window; }
            static Application& Get() { return *s_Instance; }
    };

    Application* CreateApplication(int argc, char **argv);
}