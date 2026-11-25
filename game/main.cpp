#include "XSE.h"
#include <cmath>
#include <iostream>
#include <string>

class GameTest : public xse::Application {
    private:
        float m_FixedTPS = 1.0f/15;
        float m_Angle = 0;

        int m_BaseOffsetDir = 15, m_OffsetDir = m_BaseOffsetDir;
        float m_Offset = m_BaseOffsetDir;

        xse::Vector2 m_Position {0, 0};
        xse::Vector2 m_Size {16, 16};
        xse::Vector2 m_Center = m_Size.GetCenter();
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
            xse::Vector2 screenCenter = {160-m_Center.x, 90-m_Center.y};
            float x = std::cos(m_Angle) * m_Offset;
            float y = std::sin(m_Angle) * m_Offset;

            m_Position = {x + screenCenter.x, y + screenCenter.y};
            m_Offset += m_OffsetDir * deltaTime;
            if (m_Offset >= screenCenter.y || m_Offset <= m_BaseOffsetDir)
                m_OffsetDir *= -1;

            m_Angle += deltaTime*5;
            if (m_Angle >= 6.28) m_Angle = 0;
        }

        void OnRender(float deltaTime) override {
            xse::Renderer::DrawDebug({0, 0}, "Position: " + std::to_string(m_Position.x) + ", " + std::to_string(m_Position.y));
            xse::Renderer::DrawDebug({0, 10}, "Angle: " + std::to_string(m_Angle));
            xse::Renderer::DrawDebug({0, 20}, "Offset: " + std::to_string(m_Offset) + " | Dir: " + (m_OffsetDir > 0 ? "out" : "in"));
            xse::Renderer::DrawDebug({0, 40}, "FPS: " + std::to_string((int)(1/deltaTime)));
            xse::Renderer::DrawDebug({0, 50}, "MsPF: " + std::to_string(std::round(deltaTime*1000)));

            xse::Renderer::DrawRect(m_Position, {16, 16});
        }
};

xse::Application* xse::CreateApplication(int argc, char **argv) {
    return new GameTest({
        .title = "Test"
    });
}