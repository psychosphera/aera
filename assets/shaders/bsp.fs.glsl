#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 binormal;
in vec3 tangent;
in vec2 tex_coords;
in vec3 lightmap_normal;
in vec2 lightmap_tex_coords;

uniform bool uWireframe;
uniform sampler2D uTex;

void main()
{
	if(uWireframe)
		FragColor = vec4(0.3f, 1.0f, 0.3f, 1.0f);
	else
		FragColor = vec4(texture(uTex, tex_coords).xyz, 1.0f);
}	