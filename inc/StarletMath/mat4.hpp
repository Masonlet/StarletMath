#pragma once

#include "vec3.hpp"
#include "vec4.hpp"
#include "transform.hpp"
#include "constants.hpp"
#include <cmath>

struct Mat4 {
	float models[16]{0.0f};

	inline const float* ptr() const { return models; }
	inline float* ptr() { return models; }

	static Mat4 identity() {
    Mat4 result;
    result.models[0] = 1.0f;
    result.models[5] = 1.0f;
    result.models[10] = 1.0f;
    result.models[15] = 1.0f;
    return result;
  }
  static Mat4 modelMatrix(const Transform& t) {
    return Mat4::translation(t.pos) 
      * Mat4::rotateX(t.rot.x)
      * Mat4::rotateY(t.rot.y) 
      * Mat4::rotateZ(t.rot.z) 
      * Mat4::size(t.size);
  }	
  Mat4 transpose() const {
    Mat4 result;
    for (int row = 0; row < 4; ++row) 
      for (int col = 0; col < 4; ++col) 
        result.models[col * 4 + row] = models[row * 4 + col];

    return result;
  }
  Mat4 inverse() const {
    const float* m = models;

    Mat4 inv; 
    inv.models[0] = m[5] * m[10] * m[15] -
      m[5] * m[11] * m[14] -
      m[9] * m[6] * m[15] +
      m[9] * m[7] * m[14] +
      m[13] * m[6] * m[11] -
      m[13] * m[7] * m[10];

    inv.models[4] = -m[4] * m[10] * m[15] +
      m[4] * m[11] * m[14] +
      m[8] * m[6] * m[15] -
      m[8] * m[7] * m[14] -
      m[12] * m[6] * m[11] +
      m[12] * m[7] * m[10];

    inv.models[8] = m[4] * m[9] * m[15] -
      m[4] * m[11] * m[13] -
      m[8] * m[5] * m[15] +
      m[8] * m[7] * m[13] +
      m[12] * m[5] * m[11] -
      m[12] * m[7] * m[9];

    inv.models[12] = -m[4] * m[9] * m[14] +
      m[4] * m[10] * m[13] +
      m[8] * m[5] * m[14] -
      m[8] * m[6] * m[13] -
      m[12] * m[5] * m[10] +
      m[12] * m[6] * m[9];

    inv.models[1] = -m[1] * m[10] * m[15] +
      m[1] * m[11] * m[14] +
      m[9] * m[2] * m[15] -
      m[9] * m[3] * m[14] -
      m[13] * m[2] * m[11] +
      m[13] * m[3] * m[10];

    inv.models[5] = m[0] * m[10] * m[15] -
      m[0] * m[11] * m[14] -
      m[8] * m[2] * m[15] +
      m[8] * m[3] * m[14] +
      m[12] * m[2] * m[11] -
      m[12] * m[3] * m[10];

    inv.models[9] = -m[0] * m[9] * m[15] +
      m[0] * m[11] * m[13] +
      m[8] * m[1] * m[15] -
      m[8] * m[3] * m[13] -
      m[12] * m[1] * m[11] +
      m[12] * m[3] * m[9];

    inv.models[13] = m[0] * m[9] * m[14] -
      m[0] * m[10] * m[13] -
      m[8] * m[1] * m[14] +
      m[8] * m[2] * m[13] +
      m[12] * m[1] * m[10] -
      m[12] * m[2] * m[9];

    inv.models[2] = m[1] * m[6] * m[15] -
      m[1] * m[7] * m[14] -
      m[5] * m[2] * m[15] +
      m[5] * m[3] * m[14] +
      m[13] * m[2] * m[7] -
      m[13] * m[3] * m[6];

    inv.models[6] = -m[0] * m[6] * m[15] +
      m[0] * m[7] * m[14] +
      m[4] * m[2] * m[15] -
      m[4] * m[3] * m[14] -
      m[12] * m[2] * m[7] +
      m[12] * m[3] * m[6];

    inv.models[10] = m[0] * m[5] * m[15] -
      m[0] * m[7] * m[13] -
      m[4] * m[1] * m[15] +
      m[4] * m[3] * m[13] +
      m[12] * m[1] * m[7] -
      m[12] * m[3] * m[5];

    inv.models[14] = -m[0] * m[5] * m[14] +
      m[0] * m[6] * m[13] +
      m[4] * m[1] * m[14] -
      m[4] * m[2] * m[13] -
      m[12] * m[1] * m[6] +
      m[12] * m[2] * m[5];

    inv.models[3] = -m[1] * m[6] * m[11] +
      m[1] * m[7] * m[10] +
      m[5] * m[2] * m[11] -
      m[5] * m[3] * m[10] -
      m[9] * m[2] * m[7] +
      m[9] * m[3] * m[6];

    inv.models[7] = m[0] * m[6] * m[11] -
      m[0] * m[7] * m[10] -
      m[4] * m[2] * m[11] +
      m[4] * m[3] * m[10] +
      m[8] * m[2] * m[7] -
      m[8] * m[3] * m[6];

    inv.models[11] = -m[0] * m[5] * m[11] +
      m[0] * m[7] * m[9] +
      m[4] * m[1] * m[11] -
      m[4] * m[3] * m[9] -
      m[8] * m[1] * m[7] +
      m[8] * m[3] * m[5];

    inv.models[15] = m[0] * m[5] * m[10] -
      m[0] * m[6] * m[9] -
      m[4] * m[1] * m[10] +
      m[4] * m[2] * m[9] +
      m[8] * m[1] * m[6] -
      m[8] * m[2] * m[5];

    float det = m[0] * inv.models[0] + m[1] 
      * inv.models[4] + m[2] 
      * inv.models[8] + m[3] 
      * inv.models[12];

    if (det == 0) return Mat4::identity();
    else          det = 1.0 / det;

    for (int i = 0; i < 16; ++i) inv.models[i] *= det;
    return inv;
  }
  static Mat4 translation(const Vec4& t) {
    Mat4 result = Mat4::identity();
    result.models[12] = t.x;
    result.models[13] = t.y;
    result.models[14] = t.z;
    return result;
  }
  static Mat4 size(const Vec3& t) {
    Mat4 result = Mat4::identity();
    result.models[0]  = t.x;
    result.models[5]  = t.y;
    result.models[10] = t.z;
    return result;
  }  
  static Mat4 rotateX(const float angle) {
    const float rad = radians(angle);
    float c = cosf(rad);
    float s = sinf(rad);

    Mat4 result = Mat4::identity();
    result.models[5]  =  c;
    result.models[6]  =  s;
    result.models[9]  = -s;
    result.models[10] =  c;
    return result;
  }
  static Mat4 rotateY(const float angle) {
    const float rad = radians(angle);
    float c = cosf(rad);
    float s = sinf(rad);

    Mat4 result = Mat4::identity();
    result.models[0]  =  c;
    result.models[2]  =  s;
    result.models[8]  = -s;
    result.models[10] =  c;
    return result;
  }
  static Mat4 rotateZ(const float angle) {
    const float rad = radians(angle);
    float c = cosf(rad);
    float s = sinf(rad);

    Mat4 result = Mat4::identity();
    result.models[0] =  c;
    result.models[1] =  s;
    result.models[4] = -s;
    result.models[5] =  c;
    return result;
  }
  static Mat4 lookAt(const Vec3& pos, const Vec3& front, const Vec3& up = WORLD_UP){
    const Vec3 forward = front.normalized();
    Vec3 right = forward.cross(up);
    if(right.length() < 0.00001f) right = { 1.0f, 0.0f, 0.0f };
    else                          right = right.normalized();
    const Vec3 camUp = right.cross(forward);

    Mat4 view{};
    view.models[0] = right.x;
    view.models[1] = camUp.x;
    view.models[2] = -forward.x;
    view.models[3] = 0.0f;

    view.models[4] = right.y;
    view.models[5] = camUp.y;
    view.models[6] = -forward.y;
    view.models[7] = 0.0f;

    view.models[8] = right.z;
    view.models[9] = camUp.z;
    view.models[10] = -forward.z;
    view.models[11] = 0.0f;

    view.models[12] = -right.dot(pos);
    view.models[13] = -camUp.dot(pos);
    view.models[14] = forward.dot(pos);
    view.models[15] = 1.0f;
    return view;
  }
  static Mat4 perspective(const float degFov, const float aspect, const float nearPlane, const float farPlane){
    const float tanHalfFov = tanf(radians(degFov) / 2.0f);

    Mat4 projection{};
    projection.models[0]  =   1.0f / (aspect * tanHalfFov);
    projection.models[5]  =   1.0f / tanHalfFov;
    projection.models[10] = -(farPlane + nearPlane) / (farPlane - nearPlane);
    projection.models[11] =  -1.0f;
    projection.models[14] = -(2.0f * farPlane * nearPlane) / (farPlane - nearPlane);
    projection.models[15] =   0.0f;
    return projection;
  }

  Mat4 operator*(const Mat4& b) const {
    Mat4 result{};

    // Column 0
    result.models[0] = models[0] * b.models[0] + models[4] * b.models[1] + models[8]  * b.models[2] + models[12] * b.models[3];
    result.models[1] = models[1] * b.models[0] + models[5] * b.models[1] + models[9]  * b.models[2] + models[13] * b.models[3];
    result.models[2] = models[2] * b.models[0] + models[6] * b.models[1] + models[10] * b.models[2] + models[14] * b.models[3];
    result.models[3] = models[3] * b.models[0] + models[7] * b.models[1] + models[11] * b.models[2] + models[15] * b.models[3];

    // Column 1
    result.models[4] = models[0] * b.models[4] + models[4] * b.models[5] + models[8]  * b.models[6] + models[12] * b.models[7];
    result.models[5] = models[1] * b.models[4] + models[5] * b.models[5] + models[9]  * b.models[6] + models[13] * b.models[7];
    result.models[6] = models[2] * b.models[4] + models[6] * b.models[5] + models[10] * b.models[6] + models[14] * b.models[7];
    result.models[7] = models[3] * b.models[4] + models[7] * b.models[5] + models[11] * b.models[6] + models[15] * b.models[7];

    //// Column 2
    result.models[8]  = models[0] * b.models[8] + models[4] * b.models[9] + models[8]  * b.models[10] + models[12] * b.models[11];
    result.models[9]  = models[1] * b.models[8] + models[5] * b.models[9] + models[9]  * b.models[10] + models[13] * b.models[11];
    result.models[10] = models[2] * b.models[8] + models[6] * b.models[9] + models[10] * b.models[10] + models[14] * b.models[11];
    result.models[11] = models[3] * b.models[8] + models[7] * b.models[9] + models[11] * b.models[10] + models[15] * b.models[11];

    //// Column 3
    result.models[12] = models[0] * b.models[12] + models[4] * b.models[13] + models[8]  * b.models[14] + models[12] * b.models[15];
    result.models[13] = models[1] * b.models[12] + models[5] * b.models[13] + models[9]  * b.models[14] + models[13] * b.models[15];
    result.models[14] = models[2] * b.models[12] + models[6] * b.models[13] + models[10] * b.models[14] + models[14] * b.models[15];
    result.models[15] = models[3] * b.models[12] + models[7] * b.models[13] + models[11] * b.models[14] + models[15] * b.models[15];

    return result;
  }
  Vec4 operator*(const Vec4& v) const {
    Vec4 result;
    result.x = models[0] * v.x + models[4] * v.y + models[8] * v.z + models[12] * v.w;
    result.y = models[1] * v.x + models[5] * v.y + models[9] * v.z + models[13] * v.w;
    result.z = models[2] * v.x + models[6] * v.y + models[10] * v.z + models[14] * v.w;
    result.w = models[3] * v.x + models[7] * v.y + models[11] * v.z + models[15] * v.w;
    return result;
  }

  Mat4& operator*=(const Mat4& b) {
    *this = (*this) * b;
    return *this;
  }
  bool operator==(const Mat4& b) const {
    for (int i = 0; i < 16; ++i)
      if (models[i] != b.models[i])
        return false;

    return true;
  }  

  Transform decompose() const {
    Transform t;

    t.pos.x = models[12];
    t.pos.y = models[13];
    t.pos.z = models[14];

    Vec3 col0 = {models[0], models[1], models[2] };
    Vec3 col1 = {models[4], models[5], models[6] };
    Vec3 col2 = {models[8], models[9], models[10] };

    t.size.x = col0.length();
    t.size.y = col1.length();
    t.size.z = col2.length();

    // Normalized
    if (t.size.x != 0) col0 = col0 / t.size.x;
    if (t.size.y != 0) col1 = col1 / t.size.y;
    if (t.size.z != 0) col2 = col2 / t.size.z;

    t.rot.y = asinf(-col0.z);  // Y-axis
    if (cosf(t.rot.y) != 0.0f) {
      t.rot.x = atan2f(col1.z, col2.z); // X-axis
      t.rot.z = atan2f(col0.y, col0.x); // Z-axis
    } else {
      t.rot.x = atan2f(-col2.x, col1.y); // Gimbal lock case
      t.rot.z = 0.0f;
    }

    t.rot.x = degrees(t.rot.x);
    t.rot.y = degrees(t.rot.y);
    t.rot.z = degrees(t.rot.z);

    return t;
  }
};
