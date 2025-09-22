#pragma once

#include "vec3.hpp"
#include <cmath>
#include <type_traits>

/*
Vec4
* 4-Dimensional Vector
* x, y, z, w OR r, g, b, a
*/
template <typename T>
struct Vec4 {
	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
	};

	constexpr Vec4() : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
	constexpr Vec4(T v) : x(v), y(v), z(v), w(v) {}
	constexpr Vec4(T xIn, T yIn, T zIn, T wIn) : x(xIn), y(yIn), z(zIn), w(wIn) {}
	constexpr Vec4(const Vec3<T>& v, T wIn) : x(v.x), y(v.y), z(v.z), w(wIn) {}
	constexpr Vec4(const Vec4<T>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

	Vec4& operator=(const Vec4& other) = default;

  T length() const { return std::sqrt(x * x + y * y + z * z + w * w); }
  T lengthSquared() const { return x * x + y * y + z * z + w * w; }

	Vec4<double> normalized() const requires std::is_integral_v<T> {
		double len = length();
		return (len < 1e-6) ? Vec4<double>(0.0) : Vec4<double>(x / len, y / len, z / len, w / len);
	}
	Vec4<T> normalized() const requires std::is_floating_point_v<T> {
		T len = length();
		return (len < 1e-6) ? Vec4<T>(T(0)) : Vec4<T>(x / len, y / len, z / len, w / len);
	}

	T dot(const Vec4& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

	Vec4 operator-() const { return Vec4(-x, -y, -z, -w); }

  Vec4 operator+(const Vec4& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; }
	Vec4 operator-(const Vec4& rhs) const { return { x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w}; }
	Vec4 operator*(const Vec4& rhs) const { return { x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w}; }
	Vec4 operator/(const Vec4& rhs) const { return { x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w }; }	

	Vec4 operator+(const T rhs) const { return { x + rhs, y + rhs, z + rhs, w + rhs }; }
	Vec4 operator-(const T rhs) const { return { x - rhs, y - rhs, z - rhs, w - rhs }; }
	Vec4 operator*(const T rhs) const { return { x * rhs, y * rhs, z * rhs, w * rhs }; }
	Vec4 operator/(const T rhs) const { return { x / rhs, y / rhs, z / rhs, w / rhs }; }

	Vec4& operator+=(const Vec4& rhs) { x += rhs.x, y += rhs.y, z += rhs.z, w += rhs.w; return *this; }
	Vec4& operator-=(const Vec4& rhs) { x -= rhs.x, y -= rhs.y, z -= rhs.z, w -= rhs.w; return *this; }
	Vec4& operator*=(const Vec4& rhs) { x *= rhs.x, y *= rhs.y, z *= rhs.z, w *= rhs.w; return *this; }
	Vec4& operator/=(const Vec4& rhs) { x /= rhs.x, y /= rhs.y, z /= rhs.z, w /= rhs.w; return *this; }

	Vec4& operator+=(const T rhs) { x += rhs, y += rhs, z += rhs, w += rhs; return *this; }
	Vec4& operator-=(const T rhs) { x -= rhs, y -= rhs, z -= rhs, w -= rhs; return *this; }
	Vec4& operator*=(const T rhs) { x *= rhs, y *= rhs, z *= rhs, w *= rhs; return *this; }
	Vec4& operator/=(const T rhs) { x /= rhs, y /= rhs, z /= rhs, w /= rhs; return *this; }

	bool operator==(const Vec4& rhs) { return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w; }
	bool operator!=(const Vec4& rhs) { return !(*this == rhs); }
};
