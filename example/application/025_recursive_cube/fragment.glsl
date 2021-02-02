#version 140

uniform sampler2D CubeTex;
in vec3 vertNormal;
in vec3 vertLightDir;
in vec2 vertTexCoord;
out vec4 fragColor;

void main() {
    float d = 0.3 * dot(vertNormal, normalize(vertLightDir));
    float i = 0.6 + max(d, 0.0);
    fragColor = texture(CubeTex, vertTexCoord) * i;
}
