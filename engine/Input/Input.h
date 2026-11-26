#pragma once
#include "KeyCode.h"

namespace xse {
    class Event;

    class Input {
        public:
            static bool IsKeyPressed(KeyCode key);
            static bool WasKeyPressed(KeyCode key);
            static bool WasKeyReleased(KeyCode key);

            static void BeginFrame();
            static void OnEvent(Event& event);
    };
}