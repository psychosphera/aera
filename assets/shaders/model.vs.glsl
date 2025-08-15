#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec3 aBiormal;
layout (location = 3) in vec3 aTangent;
layout (location = 4) in vec2 aTexCoords;

out vec3 normal;
out vec3 binormal;
out vec3 tangent;
out vec2 tex_coords;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uPerspectiveProjection;

vec3 Vec3SwapYZ(vec3 v) {
	float temp = v.y;
	v.y = v.z;
	v.z = temp;
	return v;
}

void main() {
	gl_Position = 
		uPerspectiveProjection * uView * uModel * vec4(Vec3SwapYZ(aPos), 1.0);
	normal              = Vec3SwapYZ(aNormal);
	binormal            = Vec3SwapYZ(aBiormal);
	tangent             = Vec3SwapYZ(aTangent);
	tex_coords          = aTexCoords;
}