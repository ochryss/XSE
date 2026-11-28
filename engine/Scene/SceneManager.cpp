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
    void SceneManager::SortScenes(bool ascending) {
        std::stable_sort(m_Scenes.begin(), m_Scenes.end(),
            [ascending](const Scene* a, const Scene* b) {
                return ascending ? a->GetSortDepth() < b->GetSortDepth()
                    : a->GetSortDepth() > b->GetSortDepth();
            }
        );
    }

    void SceneManager::OnUpdate(float deltaTime) {
        SortScenes(true);

        for (Scene* scene : m_Scenes) {
            scene->OnUpdate(deltaTime);
        }
    }

    void SceneManager::OnRender(float deltaTime) {
        SortScenes(false);

        for (Scene* scene : m_Scenes) {
            scene->OnRender(deltaTime);
        }
    }

    void SceneManager::OnEvent(Event& event) {
        SortScenes(true);

        for (Scene* scene : m_Scenes) {
            scene->OnEvent(event);
        }
    }
}