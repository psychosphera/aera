#version 330 core
in vec2 GlyphTexCoords;

uniform sampler2D uTex;
uniform vec4 uTextColor;
uniform vec4 uAtlasCoord;

out vec4 FragColor;

void main() {
	FragColor = vec4(1.0, 1.0, 1.0, texture(uTex, uAtlasCoord.xy + GlyphTexCoords * uAtlasCoord.zw).r) * vec4(uTextColor.rgb, 1.0);
}