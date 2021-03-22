#version 150
uniform sampler2D Tex;

const vec3 lightDir = normalize(vec3(1.0));
const float edgeWidth = 1.2;

noperspective in vec3 geomDist;
in vec3 geomNormal;
in vec2 geomCoord;
out vec3 fragColor;

void main() {
    float minDist = min(min(geomDist.x, geomDist.y), geomDist.z);
    float edgeAlpha = exp2(-pow(minDist / edgeWidth, 2.0));
	float light = clamp(dot(lightDir, geomNormal), 0.0, 1.0);
	float density = max(sqrt(texture(Tex, geomCoord).r) - light, 0.0);

    vec3 faceColor = mix(
		vec3(0.2),
		vec3(0.85, 0.85. 0.65) *
		mix(mix(0.1, 0.9, light), 0.0, density));
    vec3 edgeColor = vec3(0.0);

    fragColor = mix(faceColor, edgeColor, edgeAlpha);
}
