#pragma once

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

struct Vertex {
	Vec3 pos{ 0.0f };     
	Vec4 col{ 1.0f };    
	Vec3 norm{ 0.0f };    
	Vec2<float> texCoord{ 0.0f }; 
};
