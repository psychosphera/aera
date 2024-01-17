#version 330 core
in vec2 TexCoords;
out vec4 color;

uniform sampler2D uTex;
uniform vec3 uTextColor;
uniform vec4 uCoord;

void main()
{   
	vec2 v = TexCoords * uCoord.zw + uCoord.xy;
	
	vec4 sampled = vec4(1.0, 1.0, 1.0, texture(uTex, v).r);
	//vec4 sampled = vec4(v,1.0,0.5);
    color = vec4(uTextColor, 1.0) * sampled;
}