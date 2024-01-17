#version 330 core
layout (location = 0) in vec4 aVec; 

out vec2 TexCoords;

uniform mat4 uModel;
uniform mat4 uProjection;

void main()
{
    gl_Position =  uProjection * uModel * vec4(aVec.xy, 0.0, 1.0);
    TexCoords = aVec.zw;
}