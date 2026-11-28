#pragma once

namespace xse {
    class Event;

    class Scene {
        private:
            // Assure Scene can't be copied
            Scene& operator=(const Scene& rhs);
            Scene(const Scene& rhs);

            // Represents Priority on Update or Event actions
            // and Depth on Render action.
            double m_SortDepth;
        public:
            explicit Scene(double sortDepth = 0.0) : m_SortDepth(sortDepth) {}
            virtual ~Scene() = default;

            double GetSortDepth() const { return m_SortDepth; }

            virtual void OnUpdate(float deltaTime) {};
            virtual void OnRender(float deltaTime) {};
            virtual void OnEvent(Event& event) {};
    };
}