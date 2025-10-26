#pragma once

#include <cmath>
#include <type_traits>

namespace Starlet::Math {
  /*
  Vec2
  * 2-Dimensional Vector
  * x, y
  */
  template<typename T>
  struct Vec2 {
    T x, y;

    constexpr Vec2() : x(T(0)), y(T(0)) {}
    constexpr Vec2(T val) : x(val), y(val) {}
    constexpr Vec2(T xVal, T yVal) : x(xVal), y(yVal) {}
    constexpr Vec2(const Vec2& other) = default;

    Vec2& operator=(const Vec2& other) = default;

    T length() const { return std::sqrt(x * x + y * y); }
    T lengthSquared() const { return x * x + y * y; }

    Vec2<double> normalized() const requires std::is_integral_v<T> {
      double len = length();
      return (len < 1e-6) ? Vec2<double>(0) : Vec2<double>(x / len, y / len);
    }
    Vec2<T> normalized() const requires std::is_floating_point_v<T> {
      T len = static_cast<T>(length());
      return (len < 1e-6) ? Vec2<T>(0) : Vec2<T>(x / len, y / len);
    }

    T dot(const Vec2& rhs) const { return x * rhs.x + y * rhs.y; }

    Vec2 operator-() const { return Vec2(-x, -y); }

    Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
    Vec2 operator-(const Vec2& rhs) const { return Vec2(x - rhs.x, y - rhs.y); }
    Vec2 operator*(const Vec2& rhs) const { return Vec2(x * rhs.x, y * rhs.y); }
    Vec2 operator/(const Vec2& rhs) const { return Vec2(x / rhs.x, y / rhs.y); }

    Vec2 operator+(const T rhs) const { return Vec2(x + rhs, y + rhs); }
    Vec2 operator-(const T rhs) const { return Vec2(x - rhs, y - rhs); }
    Vec2 operator*(const T rhs) const { return Vec2(x * rhs, y * rhs); }
    Vec2 operator/(const T rhs) const { return Vec2(x / rhs, y / rhs); }

    Vec2& operator+=(const Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec2& operator-=(const Vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
    Vec2& operator*=(const Vec2& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
    Vec2& operator/=(const Vec2& rhs) { x /= rhs.x; y /= rhs.y; return *this; }

    Vec2& operator+=(const T rhs) { x += rhs; y += rhs; return *this; }
    Vec2& operator-=(const T rhs) { x -= rhs; y -= rhs; return *this; }
    Vec2& operator*=(const T rhs) { x *= rhs; y *= rhs; return *this; }
    Vec2& operator/=(const T rhs) { x /= rhs; y /= rhs; return *this; }

    bool operator==(const Vec2& rhs) const { return x == rhs.x && y == rhs.y; }
    bool operator!=(const Vec2& rhs) const { return !(*this == rhs); }
  };
}