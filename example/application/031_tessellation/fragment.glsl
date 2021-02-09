#version 400

noperspective in vec3 geomDist;
flat in vec3 geomNormal;
in vec3 geomColor;

out vec3 fragColor;

void main() {
    float MinDist = min(min(geomDist.x, geomDist.y), geomDist.z);
    float EdgeAlpha = exp2(-pow(MinDist, 2.0));

    vec3 FaceColor = geomColor;
    const vec3 EdgeColor = vec3(0.2, 0.2, 0.2);

    fragColor = mix(FaceColor, EdgeColor, EdgeAlpha);
}
