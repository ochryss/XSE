#pragma once
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

    class Application {
        private:
            bool m_IsTerminated = false;
            static Application* s_Instance;

            Window* m_Window = nullptr;

            ApplicationSpecification m_Specification;
        
        public:
            Application(const ApplicationSpecification& spec);
            virtual ~Application();

            virtual void OnInitialization() {}
            virtual void OnTermination() {}
            virtual void OnUpdate(float deltaTime) {}
            virtual void OnRender(float deltaTime) {}

            void Initialize();
            void Terminate();

            void HandleEvent();

            inline Window& GetWindow() const { return *m_Window; }
            static Application& Get() { return *s_Instance; }
    };

    Application* CreateApplication(int argc, char **argv);
}