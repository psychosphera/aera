#version 330 core
out vec4 FragColor;

uniform bool uWireframe;

void main()
{
	if(uWireframe)
		FragColor = vec4(0.3f, 1.0f, 0.3f, 1.0f);
	else
		FragColor = vec4(0.5f, 0.5f, 0.5f, 1.0f);
		
}