struct VS_INPUT {
    float2 Pos : POSITION;
    float2 Tex : TEXCOORD;
};

struct VS_OUTPUT {
    float4 Pos : POSITION;
    float2 Tex : TEXCOORD;
};

cbuffer cbVS {
    float4x4 uOrthoProjection;
    float4x4 uModel;
};

VS_OUTPUT main(VS_INPUT input) {
    VS_OUTPUT output;

    output.Pos = mul(uOrthoProjection * uModel, float4(input.Pos, 0.0, 1.0));
    output.Tex = input.Tex;
    return output;
}