#pragma once
#include "Event.h"
#include "Input/KeyCode.h"

namespace xse {
    class KeyPressEvent : public Event {
        private:
            KeyCode m_Keycode;
            bool m_IsRepeat;

        public:
            explicit KeyPressEvent(KeyCode keycode, bool repeat) : m_Keycode(keycode), m_IsRepeat(repeat) {}
            EVENT_CLASS_TYPE(KEY_PRESS);

            KeyCode GetKey() const { return m_Keycode; }
            bool IsRepeat() const { return m_IsRepeat; }
    };
    
    class KeyReleaseEvent : public Event {
        private:
            KeyCode m_Keycode;
            bool m_IsRepeat;

        public:
            explicit KeyReleaseEvent(KeyCode keycode, bool repeat) : m_Keycode(keycode), m_IsRepeat(repeat) {}
            EVENT_CLASS_TYPE(KEY_RELEASE);

            KeyCode GetKey() const { return m_Keycode; }
            bool IsRepeat() const { return m_IsRepeat; }
    };
}