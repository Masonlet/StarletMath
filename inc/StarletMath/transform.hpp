#pragma once

#include "vec3.hpp"
#include "vec4.hpp"

struct Transform {
	Vec4 pos{0.0f};
	Vec3 rot{0.0f};
	Vec3 size{1.0f};
};
