#include "core/Application.h"
#include <iostream>

class GameTest : public xse::Application {
    public:
        GameTest(xse::ApplicationSpecification spec) : xse::Application(spec) {}
        ~GameTest() {}

        void OnInitialization() override {
            std::cout << "Initialized" << std::endl;
        }

        void OnTermination() override {
            std::cout << "Terminated" << std::endl;
        }
        
        void OnUpdate(float deltaTime) override {
            std::cout << "Updating" << std::endl;
        }

        void OnRender(float deltaTime) override {
            std::cout << "Rendering" << std::endl;
        }
};

xse::Application* xse::CreateApplication(int argc, char **argv) {
    return new GameTest({
        .title = "Test"
    });
}