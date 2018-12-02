#version 140

in vec3 geomColor;
in vec3 geomNormal;
in vec3 geomCenter;
in vec3 geomCorner;
out vec3 fragColor;

const vec3 LightDir1 = normalize(vec3(1, 2, 3));
const vec3 LightDir2 = normalize(vec3(0, -1, 0));

const float pi_2 = 3.141592653589793238462643383 * 0.5;

void main() {
    vec3 Dir = geomCorner - geomCenter;
    float len = length(Dir);
    float mask = max(sign(1 - len * 4), 0.0);

    vec3 sNormal =
      sin((1 - len) * pi_2) * geomNormal - sin(len * pi_2) * Dir * 2.0;
    vec3 fNormal = mix(geomNormal, sNormal, mask);

    float light = dot(fNormal, LightDir1) * 1.4 + dot(fNormal, LightDir2) * 0.4;

    light = mix(light, floor(5 * light) / 5.0, mask);

    fragColor = geomColor * light;
}
