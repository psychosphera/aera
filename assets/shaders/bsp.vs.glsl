#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uPerspectiveProjection;

void main() {
	gl_Position = uPerspectiveProjection * uView * uModel * vec4(aPos, 1.0);
}