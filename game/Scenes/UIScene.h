#pragma once
#include "Scene/Scene.h"

namespace game {
    class PlayerData;

    class UIScene : public xse::Scene {
        private:
            PlayerData& m_PlayerData;
        
        public:
            explicit UIScene(PlayerData& playerData);

            void OnRender(float deltaTime) override;
            void OnEvent(xse::Event& event) override;
    };
}