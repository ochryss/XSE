#pragma once

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); };

namespace xse {
    enum class EventType {
        NONE = 0,

        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WINDOW_FOCUS,
        WINDOW_LOST_FOCUS,

        KEY_PRESS,
        KEY_RELEASE,

        MOUSE_BUTTON_PRESS,
        MOUSE_BUTTON_RELEASE,
        MOUSE_MOVE,
        MOUSE_SCROLL,
    };

    class Event {
        private:
            bool m_Handled = false;
            
        public:
            virtual ~Event() = default;

            virtual EventType GetEventType() const = 0;
            bool IsHandled() const { return m_Handled; }
            void SetHandled(bool handle) { m_Handled = handle; } 
    };
}