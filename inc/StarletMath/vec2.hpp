#pragma once

#include <cmath>

template<typename T>
struct Vec2 {
	T x{0}, y{0};

  constexpr Vec2() = default;
	constexpr Vec2(T val) : x(val), y(val) {}
  constexpr Vec2(T xVal, T yVal) : x(xVal), y(yVal) {}
  constexpr Vec2(const Vec2& other) = default;

  Vec2& operator=(const Vec2& other) = default;

  Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
  Vec2 operator-(const Vec2& rhs) const { return Vec2(x - rhs.x, y - rhs.y); }
  Vec2 operator*(T rhs) const { return Vec2(x * rhs, y * rhs); }
  Vec2 operator/(T rhs) const { return Vec2(x / rhs, y / rhs); }

  Vec2& operator+=(const Vec2& rhs) { x += rhs.x; y += rhs.y; return *this; }
  Vec2& operator-=(const Vec2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
  Vec2& operator*=(T rhs) { x *= rhs; y *= rhs; return *this; }
  Vec2& operator/=(T rhs) { x /= rhs; y /= rhs; return *this; }

  bool operator==(const Vec2& rhs) const { return x == rhs.x && y == rhs.y; }
  bool operator!=(const Vec2& rhs) const { return !(*this == rhs); }

  T length() const { return std::sqrt(x * x + y * y); }
  T lengthSquared() const { return x * x + y * y; }

  Vec2<double> normalized() const requires std::is_integral_v<T> {
    double len = length();
    return (len < 1e-6) ? Vec2<double>(0, 0) : Vec2<double>(x / len, y / len);
  }

  Vec2<T> normalized() const requires std::is_floating_point_v<T> {
    T len = length();
    return (len < 1e-6) ? Vec2<T>(0, 0) : Vec2<T>(x / len, y / len);
  }

  T dot(const Vec2& rhs) const { return x * rhs.x + y * rhs.y; }
};
