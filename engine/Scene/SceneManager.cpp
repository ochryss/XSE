#include "SceneManager.h"
#include "Event/Event.h"
#include "Scene.h"
#include <algorithm>

namespace xse {
    SceneManager::~SceneManager() {
        for (Scene* scene : m_Scenes) {
            delete scene;
        }

        m_Scenes.clear();
    }

    // The lower the SortDepth is, the earlier it is updated
    void SceneManager::SortScenes() {
        std::stable_sort(m_Scenes.begin(), m_Scenes.end(),[](const Scene* a, const Scene* b) {
            return a->GetSortDepth() < b->GetSortDepth();
        });
    }

    void SceneManager::OnUpdate(float deltaTime) {
        SortScenes();

        for (Scene* scene : m_Scenes) {
            scene->OnUpdate(deltaTime);
        }
    }

    void SceneManager::OnRender(float deltaTime) {
        SortScenes();

        for (Scene* scene : m_Scenes) {
            scene->OnRender(deltaTime);
        }
    }

    void SceneManager::OnEvent(Event& event) {
        SortScenes();

        for (Scene* scene : m_Scenes) {
            scene->OnEvent(event);
        }
    }
}