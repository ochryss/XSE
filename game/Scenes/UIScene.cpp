#include "UIScene.h"
#include "Core/Application.h"
#include "Data/Data.h"
#include "Event/Event.h"
#include "Event/KeyboardEvent.h"
#include "Graphics/Renderer.h"
#include "Math/Vector2.h"

namespace game {
    UIScene::UIScene(PlayerData& playerData)
        : xse::Scene(1), m_PlayerData(playerData) {}

    void UIScene::OnRender(float deltaTime) {
            float timeScale = xse::Application::Get().GetTimeScale();
            float realDT = (timeScale > 0) ? deltaTime/timeScale : 1;

            int fps = 1/realDT;
            float mspf = std::round(realDT*1000.0f);

            xse::Renderer::DrawDebug({0, 0}, "Position: " + m_PlayerData.position.ToString());
            
            xse::Renderer::DrawDebug({0, 20}, "FPS: " + std::to_string(fps));
            xse::Renderer::DrawDebug({0, 30}, "MsPF: " + std::to_string(mspf) + "ms");
            xse::Renderer::DrawDebug({0, 40}, "TimeScale: " + std::to_string(timeScale) + "x");
    }

    // Test for Event Handling
    // Handles the Event (which marks it as cancelled) whenever the
    // player is within bounds, allowing GameplayScene to only consider
    // the Event when it is not within bounds.
    void UIScene::OnEvent(xse::Event& event) {
        switch (event.GetEventType()) {
            case xse::EventType::KEY_RELEASE: {
                auto e = static_cast<xse::KeyReleaseEvent&>(event);
                xse::KeyCode key = e.GetKey();
                xse::Vector2 pos = m_PlayerData.position;

                if (key == xse::KeyCode::K) {
                    if ((pos.x < 320 && pos.y < 180) && (pos.x > 0 && pos.y > 0)) {
                        event.SetHandled(true);
                    }
                }

                break;
            }
            default: break;
        }
    }
}