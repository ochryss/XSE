#include "InputHelper.h"
#include "Input/Input.h"

namespace utils {
    float GetAxis(xse::KeyCode neg, xse::KeyCode pos) {
        return (int)xse::Input::IsKeyPressed(pos) - (int)xse::Input::IsKeyPressed(neg);
    }
}