#include "Data/Data.h"
#include "Event/Event.h"
#include "Event/KeyboardEvent.h"
#include "Graphics/Renderer.h"
#include "Input/KeyCode.h"
#include "Math/Vector2.h"
#include "Utils/InputHelper.h"
#include "GameplayScene.h"

namespace game {
    GameplayScene::GameplayScene(PlayerData& playerData)
        : xse::Scene(2), m_PlayerData(playerData) {}

    void GameplayScene::OnUpdate(float deltaTime) {
        float horizontalAxis = utils::GetAxis(xse::KeyCode::Left, xse::KeyCode::Right);
        float verticalAxis = utils::GetAxis(xse::KeyCode::Up, xse::KeyCode::Down);

        m_PlayerData.position += xse::Vector2(horizontalAxis, verticalAxis) * 100 * deltaTime;
    }

    void GameplayScene::OnRender(float deltaTime) {
        xse::Renderer::DrawRect(m_PlayerData.position, m_PlayerData.size, xse::Colors::Red);
    }

    // Test for Event Handling
    // Resets the player position whenever the player press K.
    // If the event is handled by UIScene, it doesn't allow it
    // to take effect.
    void GameplayScene::OnEvent(xse::Event &event) {
        if (event.IsHandled()) return;

        switch (event.GetEventType()) {
            case xse::EventType::KEY_RELEASE: {
                auto e = static_cast<xse::KeyReleaseEvent&>(event);
                xse::KeyCode key = e.GetKey();

                if (key == xse::KeyCode::K) {
                    m_PlayerData.position = {0, 0};
                }

                break;
            }
            default: break;
        }
    }
}