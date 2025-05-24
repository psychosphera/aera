struct VS_INPUT {
    float3 Pos               : POSITION;
    float3 Normal            : NORMAL0;
    float3 Biormal           : BINORMAL;
    float3 Tangent           : TANGENT;
    float2 TexCoords         : TEXCOORD0;
    float3 LightmapNormal    : NORMAL1;
    float2 LightmapTexCoords : TEXCOORD1;
};

struct VS_OUTPUT {
    float4 Pos               : POSITION;
    float3 Normal            : NORMAL0;
    float3 Biormal           : BINORMAL;
    float3 Tangent           : TANGENT;
    float2 TexCoords         : TEXCOORD0;
    float3 LightmapNormal    : NORMAL1;
    float2 LightmapTexCoords : TEXCOORD1;
};

float4x4 uModel;
float4x4 uView;
float4x4 uPerspectiveProjection;

float3 Vec3SwapYZ(float3 v) {
    float temp = v.y;
    v.y = v.z;
    v.z = temp;
    return v;
}

VS_OUTPUT main(VS_INPUT Input) {
    VS_OUTPUT Output;
    float4x4 ClipSpace = uPerspectiveProjection * uView * uModel;
    Output.Pos               = mul(ClipSpace, float4(Vec3SwapYZ(Input.Pos), 1.0));
    Output.Normal            = Vec3SwapYZ(Input.Normal);
    Output.Biormal           = Vec3SwapYZ(Input.Biormal);
    Output.Tangent           = Vec3SwapYZ(Input.Tangent);
    Output.TexCoords         = Input.TexCoords;
    Output.LightmapNormal    = Vec3SwapYZ(Input.LightmapNormal);
    Output.LightmapTexCoords = Input.LightmapTexCoords;
    return Output;
}