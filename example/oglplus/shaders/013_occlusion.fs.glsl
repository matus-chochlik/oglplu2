#version 330

uniform vec3 LightDirection;

in vec3 vertNormal;
in float vertOcclusion;
in vec2 vertCoord;

out vec3 fragColor;

const vec3 Color1 = vec3(0.52, 0.52, 0.62);
const vec3 Color2 = vec3(0.48, 0.48, 0.58);
const vec3 White = vec3(1.0);

float Pattern(vec2 tc) {
    return float(int(tc.x + tc.y) % 2);
}

void main() {
	float LightMask = clamp(1.0-vertOcclusion*0.4, 0.0, 1.0);
	float LightDot = dot(LightDirection, vertNormal);
	float LightBleed = LightMask+min(LightDot+1.0, 0.5);
		
	float Ambient = mix(0.3, 0.55, mix(LightMask, LightBleed, 0.7));
	float Diffuse = max(LightDot, 0.0) * LightBleed * 0.25;
	float Specular = pow(max(LightDot, 0.0), 64.0) * LightMask * 0.3;

	vec3 Color = mix(Color1, Color2, Pattern(vertCoord*mix(0.5, 1.0, LightMask)));
	fragColor = Color*(Ambient + Diffuse) + White*Specular;
}
