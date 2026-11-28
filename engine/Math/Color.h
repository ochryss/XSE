#pragma once

namespace xse {
    struct Color {
        int r, g, b, a = 255;

        constexpr Color(int r, int g, int b) : r(r), g(g), b(b), a(255) {}
        constexpr Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

        Color Inverted() { return Color(255,255,255) - *this; }
        void Invert() { *this = Inverted(); }

        bool operator==(const Color& other) { return r == other.r && g == other.g && b == other.b && a == other.a; }
        bool operator!=(const Color& other) { return r != other.r || g != other.g || b != other.b || a != other.a; }

        Color operator+(const Color& other) const { return { r + other.r, g + other.g, b + other.b, a + other.a }; }
        Color operator-(const Color& other) const { return { r - other.r, g - other.g, b - other.b, a - other.a }; }
        Color operator*(const Color& other) const { return { r * other.r, g * other.g, b * other.b, a * other.a }; }
        Color operator/(const Color& other) const { return { r / other.r, g / other.g, b / other.b, a / other.a }; }
        
        Color& operator+=(const Color& other) { return *this = *this + other; }
        Color& operator-=(const Color& other) { return *this = *this - other; }
        Color& operator*=(const Color& other) { return *this = *this * other; }
        Color& operator/=(const Color& other) { return *this = *this / other; }

        Color operator*(int scalar) const { return {r * scalar, g * scalar, b * scalar, a * scalar}; }
        Color operator/(int scalar) const { return {r / scalar, g / scalar, b / scalar, a / scalar}; }

        Color& operator*=(float scalar) { return *this = *this * scalar; }
        Color& operator/=(float scalar) { return *this = *this / scalar; }
    };

    namespace Colors {
        inline constexpr Color White  { 255, 255, 255 };
        inline constexpr Color Black  { 0, 0, 0 };

        inline constexpr Color Red    { 255, 0, 0 };
        inline constexpr Color Green  { 0, 255, 0 };
        inline constexpr Color Blue   { 0, 0, 255 };
        inline constexpr Color Yellow { 255, 255, 0 };
    }
}