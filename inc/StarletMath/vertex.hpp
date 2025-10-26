#pragma once

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

namespace Starlet::Math {
	struct Vertex {
		Vec3<float> pos{ 0.0f };
		Vec4<float> col{ 1.0f };
		Vec3<float> norm{ 0.0f };
		Vec2<float> texCoord{ 0.0f };
	};
}
