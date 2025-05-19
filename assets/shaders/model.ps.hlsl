struct PS_INPUT {
    float3 Normal            : NORMAL0;
    float3 Biormal           : BINORMAL;
    float3 Tangent           : TANGENT;
    float2 TexCoords         : TEXCOORD0;
    float3 LightmapNormal    : NORMAL1;
    float2 LightmapTexCoords : TEXCOORD1;
};

sampler uBaseMap            : register(s0);
sampler uPrimaryDetailMap   : register(s1);
sampler uSecondaryDetailMap : register(s2);
sampler uMicroDetailMap     : register(s3);
sampler uBumpMap            : register(s4);
sampler uMap                : register(s5);

bool uWireframe;

float4 main(PS_INPUT Input) : COLOR0 {
    if (!uWireframe) {
        return tex2D(uBaseMap, Input.TexCoords);
    } else {
        return float4(0.3f, 1.0f, 0.3f, 1.0f);
    }
}