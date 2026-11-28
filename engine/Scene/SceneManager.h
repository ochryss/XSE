#pragma once
#include <utility>
#include <vector>

namespace xse {
    class Scene;
    class Event;

    class SceneManager {
        private:
            std::vector<Scene*> m_Scenes;

            void SortScenes(bool ascending);
        public:
            ~SceneManager();
        
            void OnUpdate(float deltaTime);
            void OnRender(float deltaTime);
            void OnEvent(Event& event);

            template<typename NewScene, typename... Args>
            NewScene* PushScene(Args&&... args) {
                NewScene* scene = new NewScene(std::forward<Args>(args)...);
                m_Scenes.push_back(scene);

                return scene;
            }
    };
}