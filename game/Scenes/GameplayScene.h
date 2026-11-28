#pragma once
#include "Scene/Scene.h"

namespace game {
    class PlayerData;

    class GameplayScene : public xse::Scene {
        private:
            PlayerData& m_PlayerData;
        
        public:
            explicit GameplayScene(PlayerData& playerData);

            void OnUpdate(float deltaTime) override;
            void OnRender(float deltaTime) override;
            void OnEvent(xse::Event& event) override;
    };
}