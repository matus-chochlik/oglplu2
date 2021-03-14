#version 150
in vec3 vertNormal;
out vec3 fragColor;

void main() {
    float bl = pow(1.1 - abs(vertNormal.z), 2.0) * 0.7;
    float fl = abs(vertNormal.z) * 0.5;
    fragColor = vec3(1.0, 0.8, 0.6) * (fl + bl);
}
