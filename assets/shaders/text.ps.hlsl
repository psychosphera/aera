//cbuffer cbPS {
    sampler uTex;
    float4 uAtlasCoord;
    float4 uTextColor;
//};

float4 main(float2 Tex : TEXCOORD) : COLOR0 {
    float  Alpha = tex2D(uTex, uAtlasCoord.xy + Tex * uAtlasCoord.zw).a;
    float4 Color = float4(1.0, 1.0, 1.0, Alpha) * float4(uTextColor.rgb, 1.0);
    return Color;
}