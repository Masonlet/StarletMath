#pragma once

#include <cmath>
#include <type_traits>

/*
Vec3
* 3-Dimensional Vector
* x, y, z OR r, g, b
*/
template<typename T>
struct Vec3 {
	union {
		struct { T x, y, z; };
		struct { T r, g, b; };
	};

	constexpr Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	constexpr Vec3(T val) : x(val), y(val), z(val) {}
	constexpr Vec3(T xIn, T yIn, T zIn) : x(xIn), y(yIn), z(zIn) {}
	constexpr Vec3(const Vec3& other) = default;

	Vec3& operator=(const Vec3& other) = default;

  double length() const {  return std::sqrt(static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z); }
  double lengthSquared() const { return static_cast<double>(x) * x + static_cast<double>(y) * y + static_cast<double>(z) * z; }

	Vec3<double> normalized() const requires std::is_integral_v<T> {
		double len = length();
		return (len < 1e-6) ? Vec3<double>(0.0) : Vec3<double>(x / len, y / len, z / len);
	}
	Vec3<T> normalized() const requires std::is_floating_point_v<T> {
		T len = length();
		return (len < 1e-6) ? Vec3<T>(T(0)) : Vec3<T>(x / len, y / len, z / len);
	}

  Vec3 cross(const Vec3& rhs) const { return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x }; }
  T dot(const Vec3& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }

	Vec3 operator-() const { return Vec3(-x, -y, -z); }

	Vec3 operator+(const Vec3& rhs) const { return Vec3{ x + rhs.x, y + rhs.y, z + rhs.z }; }
	Vec3 operator-(const Vec3& rhs) const { return Vec3{ x - rhs.x, y - rhs.y, z - rhs.z }; }
	Vec3 operator*(const Vec3& rhs) const { return Vec3{ x * rhs.x, y * rhs.y, z * rhs.z }; }
	Vec3 operator/(const Vec3& rhs) const { return Vec3{ x / rhs.x, y / rhs.y, z / rhs.z }; }

	Vec3 operator+(const T rhs) const { return Vec3{ x + rhs, y + rhs, z + rhs }; }
	Vec3 operator-(const T rhs) const { return Vec3{ x - rhs, y - rhs, z - rhs }; }
	Vec3 operator*(const T rhs) const { return Vec3{ x * rhs, y * rhs, z * rhs }; }
	Vec3 operator/(const T rhs) const { return Vec3{ x / rhs, y / rhs, z / rhs }; }

	Vec3& operator+=(const Vec3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	Vec3& operator-=(const Vec3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
	Vec3& operator*=(const Vec3& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; return *this; }
	Vec3& operator/=(const Vec3& rhs) { x /= rhs.x; y /= rhs.y; z /= rhs.z; return *this; }

	Vec3& operator+=(const T rhs) { x += rhs; y += rhs; z += rhs; return *this; }
	Vec3& operator*=(const T rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }
	Vec3& operator-=(const T rhs) { x -= rhs; y -= rhs; z -= rhs; return *this; }
	Vec3& operator/=(const T rhs) { x /= rhs; y /= rhs; z /= rhs; return *this; }

	bool operator==(const Vec3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
	bool operator!=(const Vec3& rhs) const { return !(*this == rhs); }
};
