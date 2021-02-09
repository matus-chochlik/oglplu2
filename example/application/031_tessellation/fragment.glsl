#version 400

noperspective in vec3 geomDist;
flat in vec3 geomNormal;
in vec3 geomColor;
in vec3 geomLightDir;

out vec3 fragColor;

void main() {
    float MinDist = min(min(geomDist.x, geomDist.y), geomDist.z);
    float EdgeAlpha = exp2(-pow(MinDist, 2.0));

    const float Ambient = 0.8;
    float Diffuse = max(dot(
        normalize(geomNormal),
        normalize(geomLightDir)
    ), 0.0);

    vec3 FaceColor = geomColor * (Diffuse + Ambient);
    const vec3 EdgeColor = vec3(0.0, 0.0, 0.0);

    fragColor = mix(FaceColor, EdgeColor, EdgeAlpha);
}
