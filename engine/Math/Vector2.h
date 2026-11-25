#pragma once
#include <cmath>
#include <string>

namespace xse {
    template<typename T>
    struct BaseVector2 {
        T x, y;

        std::string ToString() const {
            return std::to_string(x) + ", " + std::to_string(y);
        }

        float LengthSq() const {
            return (x * x) + (y * y);
        }

        float Length() {
            return std::sqrt(LengthSq());
        }

        BaseVector2 GetCenter() const {
            return *this / 2;
        }

        BaseVector2 Normalized() const {
            assert(x != 0 || y != 0);
            float len = Length();
            if (len > 0.0f) { return *this / len; }

            return {0.0f, 0.0f};
        }

        constexpr float Dot(const BaseVector2& other) const {
            return x * other.x + y * other.y;
        }

        float Distance(const BaseVector2& other) const {
            return (*this - other).Length();
        }

        constexpr float DistanceSq(const BaseVector2& other) const {
            return (*this - other).LengthSq();
        }

        explicit operator BaseVector2<float>() const { return BaseVector2<float>((float)x, (float)y); }
        explicit operator BaseVector2<int>() const { return BaseVector2<int>((int)x, (int)y); }

        bool operator==(const BaseVector2& other) { return x == other.x && y == other.y; }
        bool operator!=(const BaseVector2& other) { return x != other.x || y != other.y; }

        BaseVector2 operator+(const BaseVector2& other) const { return { x + other.x, y + other.y}; }
        BaseVector2 operator-(const BaseVector2& other) const { return { x - other.x, y - other.y}; }
        BaseVector2 operator*(const BaseVector2& other) const { return { x * other.x, y * other.y}; }
        BaseVector2 operator/(const BaseVector2& other) const { return { x / other.x, y / other.y}; }

        template<typename U>
        BaseVector2 operator*(U scalar) const { return { x * scalar, y * scalar}; }
        template<typename U>
        BaseVector2 operator/(U scalar) const { return { x / scalar, y / scalar}; }

        BaseVector2& operator+=(const BaseVector2& other) { return *this = *this + other; }
        BaseVector2& operator-=(const BaseVector2& other) { return *this = *this - other; }
        BaseVector2& operator*=(const BaseVector2& other) { return *this = *this * other; }
        BaseVector2& operator/=(const BaseVector2& other) { return *this = *this / other; }

        template<typename U>
        BaseVector2& operator*=(U scalar) { return *this = *this * scalar; }
        template<typename U>
        BaseVector2& operator/=(U scalar) { return *this = *this / scalar; }
    };

    using Vector2 = BaseVector2<float>;
    using Vector2i = BaseVector2<int>;
}