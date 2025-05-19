#version 330 core
out vec4 FragColor;

in vec3 normal;
in vec3 binormal;
in vec3 tangent;
in vec2 tex_coords;
in vec3 lightmap_normal;
in vec2 lightmap_tex_coords;

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
uniform vec4      uAmbientColor;
/*
uniform vec4      uDistantLight0Dir;
uniform vec4      uDistantLight1Dir;
uniform vec4      uDistantLight0Color;
uniform vec4      uDistantLight1Color;
*/

/*
vec3 shader_detail_double_biased_multiply(vec3 base, vec3 detail) {
	return clamp(base * detail * 2.0f, 0.0f, 1.0f);
}

vec3 shader_detail_mutiply(vec3 base, vec3 detail) {
	return clamp(base * detail, 0.0f, 1.0f);
}

vec3 shader_detail_double_biased_add(vec3 base, vec3 detail) {
	return clamp(base + (2.0f * detail - 1.0f), 0.0f, 1.0f);
}

vec3 shader_detail_map(vec3 base, vec3 detail, int fn) {
	if (fn == 0) return shader_detail_double_biased_multiply(base, detail);
	if (fn == 1) return shader_detail_mutiply(base, detail);
	if (fn == 2) return shader_detail_double_biased_add(base, detail);
	return base;
}	
*/

void main() {
	if(uWireframe) {
		FragColor = vec4(0.3f, 1.0f, 0.3f, 1.0f);
	} else {
		vec4 BaseColor = texture(uBaseMap, tex_coords);

		/*
		vec4 PrimaryDetailColor = vec4(1.0f);
		if (HasPrimaryDetailMap)
			PrimaryDetailColor = texture(uPrimaryDetailMap, lightmap_tex_coords);
		PrimaryDetailColor.rgb = vec3(shader_detail_map(
			BaseColor.rgb, PrimaryDetailColor.rgb, uDetailMapFunction
		));

		vec4 SecondaryDetailColor = vec4(1.0f);
		if (HasSecondaryDetailMap)
			SecondaryDetailColor = texture(uSecondaryDetailMap, lightmap_tex_coords);
		SecondaryDetailColor.rgb = vec3(shader_detail_map(
			BaseColor.rgb, SecondaryDetailColor.rgb, uDetailMapFunction
		));

		vec4 MicroDetailColor = vec4(1.0f);
		if (HasMicroDetailMap)
			MicroDetailColor = texture(uMicroDetailMap, lightmap_tex_coords);
		MicroDetailColor.rgb = vec3(shader_detail_map(
			BaseColor.rgb, MicroDetailColor.rgb, uMicroDetailMapFunction
		));

		vec4 BumpColor = vec4(1.0f);
		if (HasBumpMap)
			BumpColor = texture(uBumpMap, lightmap_tex_coords);
		*/
		
		//float DistantLight0Diff = max(dot(normal, uDistantLight0Dir.xyz), 0.0);
		//float DistantLight1Diff = max(dot(normal, uDistantLight1Dir.xyz), 0.0);

		//vec3 DistantLight0Diffuse = clamp(DistantLight0Diff * uDistantLight0Color.rgb, 0.0f, 1.0f);
		//vec3 DistantLight1Diffuse = clamp(DistantLight1Diff * uDistantLight1Color.rgb, 0.0f, 1.0f);

		//vec3 Diffuse = mix(DistantLight0Diffuse, DistantLight1Diffuse, 0.5f);
		vec3 Diffuse = vec3(1.0f);
		
		/*
		vec4 DetailColor = vec4(1.0f);
		if (HasPrimaryDetailMap && HasSecondaryDetailMap)
			DetailColor = mix(PrimaryDetailColor, SecondaryDetailColor, 0.5);
		else if (HasPrimaryDetailMap)
			DetailColor = PrimaryDetailColor;
		else if (HasSecondaryDetailMap)
			DetailColor = SecondaryDetailColor;
		*/

		vec4 Color = BaseColor;
		/*
		if (HasPrimaryDetailMap)
			Color = vec4(mix(BaseColor, DetailColor, 0.5));
		*/
		/*
		if (uAlphaTested) {
			if (BumpColor.w < 0.5)
				discard;
			FragColor = vec4(clamp(
				BaseColor.rgb * PrimaryDetailColor.rgb * 
				SecondaryDetailColor.rgb * MicroDetailColor.rgb * BumpColor.rgb *
				(Ambient.rgb + DistantLight0Diffuse + DistantLight1Diffuse), 
				0.0f, 1.0f
			), BumpColor.w);
		} else {
		*/
			FragColor = vec4(clamp(
				 Color.rgb * // MapColor.rgb * //PrimaryDetailColor.rgb * 
				//SecondaryDetailColor.rgb * MicroDetailColor.rgb * BumpColor.rgb *
				(uAmbientColor.rgb + Diffuse.rgb), 
				0.0f, 1.0f
			), 1.0f);
		//}
	}
}	