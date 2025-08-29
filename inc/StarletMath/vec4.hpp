#pragma once

#include "vec3.hpp"
#include <cmath>

/*
Vec4
* 4-Dimensional Floating Point Vector
* float x, float y, float z, float w
*/
struct Vec4 {
	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
	};

	constexpr Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
	constexpr Vec4(const Vec4& b) { x = b.x, y = b.y, z = b.z, w = b.w; };
	constexpr Vec4(float f) : x(f), y(f), z(f), w(f) {}
	Vec4(const Vec3& v, float wIn) : x(v.x), y(v.y), z(v.z), w(wIn) {}
	Vec4(unsigned int x, const Vec3& v) : x(x), y(v.x), z(v.y), w(v.z) {}
  constexpr Vec4(float xIn, float yIn, float zIn, float wIn) { x = xIn, y = yIn, z = zIn, w = wIn; }

  float length() const { 
    return sqrt(x * x + y * y + z * z + w * w); 
  }
  inline float lengthSquared() const { return x * x + y * y + z * z + w * w; }

  Vec4 normalized() const {
    float len = lengthSquared();
    if (len < 1e-6f) return {0.0f, 0.0f, 0.0f, 0.0f};

    len = sqrt(len);
    return {x / len, y / len, z / len, w / len};
  }

	inline float dot(const Vec4& b) const { return x * b.x + y * b.y + z * b.z + w * b.w; }

	inline Vec4 operator+(const Vec4& b) const { return {x + b.x, y + b.y, z + b.z, w + b.w }; }
	inline Vec4 operator-(const Vec4& b) const { return {x - b.x, y - b.y, z - b.z, w - b.w}; }
	inline Vec4 operator*(const Vec4& b) const { return {x * b.x, y * b.y, z * b.z, w * b.w}; }
	inline Vec4& operator+=(const Vec4& b) {
		x += b.x, y += b.y, z += b.z, w += b.w;
		return *this;
	}
	inline Vec4& operator-=(const Vec4& b) {
		x -= b.x, y -= b.y, z -= b.z, w -= b.w;
		return *this;
	}

	inline Vec4 operator+(const float b) const { return {x + b, y + b, z + b, w + b}; }
	inline Vec4 operator-(const float b) const { return {x - b, y - b, z - b, w - b}; }
	inline Vec4 operator*(const float b) const { return {x * b, y * b, z * b, w * b}; }
	inline Vec4& operator+=(const float b) {
		x += b, y += b, z += b, w += b;
		return *this;
	}
	inline Vec4& operator-=(const float b) {
		x -= b, y -= b, z -= b, w -= b;
		return *this;
	}

	inline bool operator!=(const Vec4& b) {
		return x != b.x && y != b.y && z != b.z && w != b.w;
	}
};
