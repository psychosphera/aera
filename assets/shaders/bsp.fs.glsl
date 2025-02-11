#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 binormal;
in vec3 tangent;
in vec2 tex_coords;
in vec3 lightmap_normal;
in vec2 lightmap_tex_coords;

uniform int       uFlags;
uniform sampler2D uBaseMap;
uniform sampler2D uPrimaryDetailMap;
uniform sampler2D uSecondaryDetailMap;
uniform sampler2D uMicroDetailMap;
uniform int       uDetailMapFunction;
uniform int       uMicroDetailMapFunction;
uniform vec3      uAmbientColor;
uniform vec3      uDistantLight0Dir;
uniform vec3      uDistantLight1Dir;
uniform vec3      uDistandLight0Color;
uniform vec3      uDistandLight1Color;

vec3 shader_detail_map(vec3 base, vec3 detail, int fn) {
	vec3 color;
	if (fn == 0)
		color = base * detail * 2.0f;
	else if (fn == 1)
		color = base * detail;
	else if (fn == 2)
		color = base + (2.0f * detail - 1.0f);
	return clamp(color, 0.0f, 1.0f);
}	

void main() {
	bool Wireframe             = (uFlags & 0x01) != 0;
	bool HasBaseMap            = (uFlags & 0x02) != 0;
	bool HasPrimaryDetailMap   = (uFlags & 0x04) != 0;
	bool HasSecondaryDetailMap = (uFlags & 0x08) != 0;
	bool HasMicroDetailMap     = (uFlags & 0x10) != 0;

	if(Wireframe) {
		FragColor = vec4(0.3f, 1.0f, 0.3f, 1.0f);
	} else {
		vec4 BaseColor = vec4(1.0f);
		if (HasBaseMap)
			BaseColor = texture(uBaseMap, tex_coords);

		vec4 PrimaryDetailColor = vec4(1.0f);
		//if (HasPrimaryDetailMap)
			PrimaryDetailColor = texture(uPrimaryDetailMap, lightmap_tex_coords);
		//PrimaryDetailColor.rgb = vec3(shader_detail_map(
		//	BaseColor.rgb, PrimaryDetailColor.rgb, uDetailMapFunction
		//));

		vec4 SecondaryDetailColor = vec4(1.0f);
		//if (HasSecondaryDetailMap)
		//	SecondaryDetailColor = texture(uSecondaryDetailMap, lightmap_tex_coords);
		//SecondaryDetailColor.rgb = vec3(shader_detail_map(
		//	BaseColor.rgb, SecondaryDetailColor.rgb, uDetailMapFunction
		//));

		vec4 MicroDetailColor = vec4(1.0f);
		//if (HasMicroDetailMap)
		//	MicroDetailColor = texture(uMicroDetailMap, lightmap_tex_coords);
		//MicroDetailColor.rgb = vec3(shader_detail_map(
		//	BaseColor.rgb, MicroDetailColor.rgb, uMicroDetailMapFunction
		//));

		float DistantLight0Diff = max(dot(lightmap_normal, uDistantLight0Dir), 0.0);
		float DistantLight1Diff = max(dot(lightmap_normal, uDistantLight1Dir), 0.0);

		vec3 DistantLight0Diffuse = DistantLight0Diff * uDistandLight0Color;
		vec3 DistantLight1Diffuse = DistantLight1Diff * uDistandLight1Color;

		FragColor = vec4(clamp(
			BaseColor.rgb * PrimaryDetailColor.rgb * 
			SecondaryDetailColor.rgb * MicroDetailColor.rgb * 
			(uAmbientColor + DistantLight0Diffuse + DistantLight1Diffuse), 
			0.0f, 1.0f
		), 1.0f);
	}
}	