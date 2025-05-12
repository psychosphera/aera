#define SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_MULTIPLY 0
#define SHADER_DETAIL_FUNCTION_MULTIPLY               1
#define SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_ADD      2

#define SHADER_ENVIRONMENT_TYPE_NORMAL                0
#define SHADER_ENVIRONMENT_TYPE_BLENDED               1
#define SHADER_ENVIRONMENT_TYPE_BLENDED_BASE_SPECULAR 2

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

bool    uWireframe;
int     uType;
int     uDetailMapFunction;
int     uMicroDetailMapFunction;
float4  uMaterialColor;
float4  uAmbientColor;
float4  uDistantLight0Dir;
float4  uDistantLight1Dir;
float4  uDistantLight0Color;
float4  uDistantLight1Color;

/*
float3 ShaderDetailDoubleBiasedMultiply(float3 Base, float3 Detail, float3 DetailMask) {
    Detail = lerp(0.5, Detail, DetailMask);
    return saturate(Base * Detail * 2.0);
}

float3 ShaderDetailMutiply(float3 Base, float3 Detail, float3 DetailMask) {
    Detail = lerp(0.5, Detail, DetailMask);
    return saturate(Base * Detail * 1.0);
}

float3 ShaderDetailDoubleBiasedAdd(float3 Base, float3 Detail, float3 DetailMask) {
    Detail = lerp(0.5, Detail, DetailMask);
    float3 BiasedDetail = 2.0 * Detail - 1.0;
    return saturate(Base + BiasedDetail);
}

float3 ShaderDetailMap(float3 Base, float3 Detail, float3 DetailMask, int Fn) {
    if (SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_MULTIPLY == 0)
        return ShaderDetailDoubleBiasedMultiply(Base, Detail, DetailMask);
    if (SHADER_DETAIL_FUNCTION_MULTIPLY == 1)
        return ShaderDetailMutiply(Base, Detail, DetailMask);
    if (SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_ADD == 2)
        return ShaderDetailDoubleBiasedAdd(Base, Detail, DetailMask);
    return Base;
}
*/

float4 main(PS_INPUT Input) : COLOR0 {
    if (uWireframe) {
        float4 BaseColor = tex2D(uBaseMap, Input.TexCoords);
    /*
    float4 PrimaryDetailColor   = 1.0f;
    float4 SecondaryDetailColor = 1.0f;
    float4 MicroDetailColor     = 1.0f;
    if (uType > SHADER_ENVIRONMENT_TYPE_NORMAL) {
        PrimaryDetailColor   = tex2D(uPrimaryDetailMap,   Input.TexCoords);
        SecondaryDetailColor = tex2D(uSecondaryDetailMap, Input.TexCoords);
        MicroDetailColor     = tex2D(uMicroDetailMap,     Input.TexCoords);
    }
    */
        float3 Ambient = clamp(uAmbientColor * uMaterialColor, 0.0f, 1.0f);
        float4 Color = float4(BaseColor.rgb * Ambient, 1.0);
        return Color;
    }
    else {
        return float4(0.3f, 1.0f, 0.3f, 1.0f);
    }
}