#pragma once

#include "vec3.hpp"
#include "vec4.hpp"

struct Transform {
	Vec4<float> pos{0.0f};
	Vec3<float> rot{0.0f};
	Vec3<float> size{1.0f};
};
