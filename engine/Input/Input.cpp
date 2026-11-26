#include "Input.h"
#include "Event/KeyboardEvent.h"
#include "KeyCode.h"
#include "SDL3/SDL_scancode.h"
#include <array>
#include <cstddef>

namespace xse {
    namespace {
        struct InputState {
            std::array<bool, SDL_SCANCODE_COUNT> keys{};
            std::array<bool, SDL_SCANCODE_COUNT> keysPressed{};
            std::array<bool, SDL_SCANCODE_COUNT> keysReleased{};
        };

        InputState s_State{};
    }

    void Input::BeginFrame() {
        s_State.keysPressed.fill(false);
        s_State.keysReleased.fill(false);
    }

    void Input::OnEvent(Event &event) {
        switch (event.GetEventType()) {
            case EventType::KEY_PRESS: {
                auto& e = static_cast<KeyPressEvent&>(event);
                KeyCode xseKey = e.GetKey();
                const auto key = static_cast<size_t>(xseKey);

                if (key >= s_State.keys.size()) break;
                if (!s_State.keys[key]) {
                    s_State.keysPressed[key] = true;
                }

                s_State.keys[key] = true;
                break;
            }

            case EventType::KEY_RELEASE: {
                auto& e = static_cast<KeyReleaseEvent&>(event);
                KeyCode xseKey = e.GetKey();
                const auto key = static_cast<size_t>(xseKey);

                if (key >= s_State.keys.size()) break;
                if (s_State.keys[key]) s_State.keysReleased[key] = true;

                s_State.keys[key] = false;
                break;
            }

            default:
                break;
        }
    }

    bool Input::IsKeyPressed(KeyCode key) {
        const auto index = static_cast<size_t>(key);

        return index < s_State.keys.size()
            && s_State.keys[index];
    }

    bool Input::WasKeyPressed(KeyCode key) {
        const auto index = static_cast<size_t>(key);

        return index < s_State.keysPressed.size()
            && s_State.keysPressed[index];
    }

    bool Input::WasKeyReleased(KeyCode key) {
        const auto index = static_cast<size_t>(key);

        return index < s_State.keysReleased.size()
            && s_State.keysReleased[index];
    }
}