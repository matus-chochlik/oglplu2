#version 140

const vec3 Color1 = vec3(0.1, 0.1, 0.1);
const vec3 Color2 = vec3(0.8, 0.6, 0.1);

in vec3 vertNormal;
in vec2 vertTCoord;
in float vertOccl;
in vec3 vertLightDir[5];
out vec3 fragColor;

float
Pattern(vec2 tc) {
    return float(int(tc.x + tc.y) % 2);
}

void
main(void) {
    float O = min(pow(vertOccl + 0.2, 6), 1);
    float A1 = pow(O, 2) * 0.1;
    float A2 = sqrt(O) * 0.1;
    float D1 = 0;
    float D2 = 0;
    float S1 = 0;
    float S2 = 0;
    for(int i = 0; i < 5; ++i) {
	vec3 LD = vertLightDir[i];
	float L = length(LD);
	float DL = dot(vertNormal, LD / L);
	D1 += max(DL / L, 0) * 2;
	D2 += sqrt(max(DL / L, 0)) * 1.2;
	S1 += pow(clamp(DL + 1.0 / L, 0, 1), 256) * 0.7;
	S2 += pow(clamp(DL + 1.5 / L, 0, 1), 16) * 0.2;
    }
    fragColor = mix(O * ((A1 + D1 + S1 * 0.5) * Color1 + vec3(S1)),
      O * ((A2 + D2 + S2 * 0.5) * Color2 + vec3(S2)),
      Pattern(vertTCoord));
}
