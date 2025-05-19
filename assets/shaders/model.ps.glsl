#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 binormal;
in vec3 tangent;
in vec2 tex_coords;

//uniform bool      uAlphaTested;
uniform bool      uWireframe;
uniform sampler2D uBaseMap;
/*
uniform sampler2D uPrimaryDetailMap;
uniform sampler2D uSecondaryDetailMap;
uniform sampler2D uMicroDetailMap;
uniform sampler2D uBumpMap;
uniform sampler2D uMap;
uniform int       uDetailMapFunction;
uniform int       uMicroDetailMapFunction;
*/

void main() {
	if(uWireframe) {
		FragColor = vec4(0.3f, 1.0f, 0.3f, 1.0f);
	} else {
		FragColor = texture(uBaseMap, tex_coords);
	}
}	