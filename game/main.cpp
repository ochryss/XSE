#include "Core/Application.h"
#include "Data/Data.h"
#include "Scene/SceneManager.h"
#include "Scenes/GameplayScene.h"
#include "Scenes/UIScene.h"
#include "XSE.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace xse;

namespace game {
    class GameTest : public Application {
        private:
            PlayerData* m_PlayerData;

        public:
            GameTest(ApplicationSpecification spec) : Application(spec) {}

            void OnInitialization() override {
                SceneManager& director = Application::Get().GetSceneManager();
                m_PlayerData = new PlayerData({144, 74}, {16, 16});

                director.PushScene<GameplayScene>(*m_PlayerData);
                director.PushScene<UIScene>(*m_PlayerData);
            }
    };
}

// class GameTest : public Application {
//     private:
//         float m_Angle = 0;

//         int m_BaseOffsetDir = 15, m_OffsetDir = m_BaseOffsetDir;
//         float m_Offset = m_BaseOffsetDir;

//         Vector2 m_Position {0, 0};
//         Vector2 m_Size {16, 16};
//         Vector2 m_Center = m_Size.GetCenter();
//     public:
//         GameTest(ApplicationSpecification spec) : Application(spec) {}
//         ~GameTest() {}

//         void OnInitialization() override {
//             std::cout << "Initialized" << std::endl;
//             Application::Get().GetSceneManager().PushScene<GameplayScene>()
//         }

//         void OnTermination() override {
//             std::cout << "Terminated" << std::endl;
//         }
        
//         void OnUpdate(float deltaTime) override {
//             Vector2 screenCenter = Vector2(160, 90) - m_Center;
//             float x = std::cos(m_Angle) * m_Offset;
//             float y = std::sin(m_Angle) * m_Offset;

//             m_Position = Vector2(x, y) + screenCenter;
//             m_Offset += m_OffsetDir * deltaTime;

//             if (m_Offset >= screenCenter.y) m_OffsetDir = -m_BaseOffsetDir;
//             if (m_Offset <= m_BaseOffsetDir) m_OffsetDir = m_BaseOffsetDir;

//             m_Angle += deltaTime*5;
//             if (m_Angle >= 6.28) m_Angle = 0;

//             HandleTimeControl(deltaTime);
//         }

//         // State-driven Input Test
//         void HandleTimeControl(float deltaTime) {
//             float timeScale = GetTimeScale();
//             if (timeScale == 0) return;

//             if (Input::IsKeyPressed(KeyCode::Up)) {
//                 timeScale += deltaTime / timeScale;
//             }

//             if (Input::WasKeyPressed(KeyCode::Right)) {
//                 timeScale += 5;
//             }

//             if (Input::WasKeyPressed(KeyCode::Left)) {
//                 timeScale -= 5;
//             }

//             if (Input::IsKeyPressed(KeyCode::Down)) {
//                 timeScale -= deltaTime / timeScale;
//             }

//             SetTimeScale(timeScale);
//         }

//         // Event-driven Input test
//         void OnEvent(Event &event) override {
//             switch (event.GetEventType()) {
//                 case EventType::KEY_PRESS: {
//                     KeyCode key = static_cast<KeyPressEvent&>(event).GetKey();
//                     int timeScale = GetTimeScale();
//                     // Yes, i use switch A LOT, cry about it.
//                     switch (key) {
//                         case KeyCode::Enter: {SetTimeScale(timeScale == 0 ? 1 : 0); break;}
//                         case KeyCode::Escape: {Terminate(); break;}
//                         default: break;
//                     }

//                     std::cout << "Key pressed: " + std::to_string((int)key) << std::endl;
//                 }

//                 default:
//                     break;
//             }
//         }

//         void OnRender(float deltaTime) override {
//             float timeScale = GetTimeScale();
//             float realDT = (timeScale > 0) ? deltaTime/timeScale : 1;

//             int fps = 1/realDT;
//             float mspf = std::round(realDT*1000.0f);

//             Renderer::DrawDebug({0, 0}, "Position: " + m_Position.ToString());
//             Renderer::DrawDebug({0, 10}, "Angle: " + std::to_string(m_Angle));
//             Renderer::DrawDebug({0, 20}, "Offset: " + std::to_string(m_Offset) + " | Dir: " + (m_OffsetDir > 0 ? "out" : "in"));
            
//             Renderer::DrawDebug({0, 40}, "FPS: " + std::to_string(fps));
//             Renderer::DrawDebug({0, 50}, "MsPF: " + std::to_string(mspf) + "ms");
//             Renderer::DrawDebug({0, 60}, "TimeScale: " + std::to_string(timeScale) + "x");

//             Renderer::DrawRect(m_Position, {16, 16});
//         }
// };

Application* xse::CreateApplication(int argc, char **argv) {
    return new game::GameTest({
        .title = "Test"
    });
}