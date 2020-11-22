#version 140
in vec3 vertNormal;
in vec2 vertWrapCoord;

out vec3 fragColor;

uniform sampler2D ColorTex;
uniform sampler2D LightTex;

const vec3 lightDir = normalize(vec3(7.0, 8.0, 9.0));

void main() {
	vec3 color = texture(ColorTex, vertWrapCoord).rgb;
	float occl = texture(LightTex, vertWrapCoord).r;

    float ambient = occl;
    float diffuse = max(dot(lightDir, vertNormal), 0.0) * pow(occl, 4.0);

    fragColor = color * (ambient + diffuse);
}
