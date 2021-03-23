#version 140

const float EdgeWidth = 1.2;

noperspective in vec3 geomDist;
in vec3 geomNormal;
out vec3 fragColor;

void main() {
    float MinDist = min(min(geomDist.x, geomDist.y), geomDist.z);
    float EdgeAlpha = exp2(-pow(MinDist / EdgeWidth, 2.0));

    vec3 FaceColor = normalize(vec3(1) - geomNormal);
    vec3 EdgeColor = vec3(0.0, 0.0, 0.0);

    fragColor = mix(FaceColor, EdgeColor, EdgeAlpha);
}
