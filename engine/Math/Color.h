#pragma once

namespace xse {
    struct Color {
        int r, g, b, a = 255;

        Color(int r, int g, int b) : r(r), g(g), b(b), a(255) {}
        Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}

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
}