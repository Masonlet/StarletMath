#pragma once

#include <cmath>

/*
Vec3
* 3-Dimensional Floating Point Vector
* float x, float y, float z
*/
struct Vec3 {
	union {
		struct { float x, y, z; };
		struct { float r, g, b; };
	};

	constexpr Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
	constexpr Vec3(const Vec3& b) : x{ b.x }, y{ b.y }, z{ b.z } {};
	constexpr Vec3(float f) : x(f), y(f), z(f) {}
	constexpr Vec3(float xIn, float yIn, float zIn) : x(xIn), y(yIn), z(zIn) {}

  float length() const { 
    return sqrt(x * x + y * y + z * z); 
  }
  inline float lengthSquared() const { return x * x + y * y + z * z; }

  Vec3 normalized() const {
    float len = lengthSquared();
    if (len < 1e-6f) return {0.0f, 0.0f, 0.0f};

    len = sqrt(len);
    return {x / len, y / len, z / len};
  }	

  inline Vec3 cross(const Vec3& b) const { return { y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x }; }
  inline float dot(const Vec3& b) const { return x * b.x + y * b.y + z * b.z; }

	inline Vec3 operator+(const Vec3& b) const { return { x + b.x, y + b.y, z + b.z }; }
	inline Vec3 operator-(const Vec3& b) const { return { x - b.x, y - b.y, z - b.z }; }
	inline Vec3 operator*(const Vec3& b) const { return { x * b.x, y * b.y, z * b.z }; }
	inline Vec3& operator+=(const Vec3& b) {
		x += b.x, y += b.y, z += b.z;
		return *this;
	}
	inline Vec3& operator-=(const Vec3& b) {
		x -= b.x, y -= b.y, z -= b.z;
		return *this;
	}

	inline Vec3 operator+(const float b) const { return { x + b, y + b, z + b }; }
	inline Vec3 operator-(const float b) const { return { x - b, y - b, z - b }; }
	inline Vec3 operator*(const float b) const { return { x * b, y * b, z * b }; }
	inline Vec3 operator/(const float b) const { return { x / b, y / b, z / b }; }
	inline Vec3& operator+=(const float b) {
		x += b, y += b, z += b;
		return *this;
	}
	inline Vec3& operator*=(const float b) {
		x *= b, y *= b, z *= b;
		return *this;
	}
	inline Vec3& operator-=(const float b) {
		x -= b, y -= b, z -= b;
		return *this;
	}

	inline bool operator!=(const Vec3& b) const {
		return x != b.x || y != b.y || z != b.z;
	}
};
