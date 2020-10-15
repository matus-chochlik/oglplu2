#version 330

in vec3 geomNormal;
in vec3 geomColor;
in float geomAmbient;
in float geomEmission;
in float geomDiffuse;
in float geomSpecular;

out vec3 fragColor;

void main() {
    fragColor = geomColor * (geomAmbient + geomDiffuse + geomEmission) +
                vec3(1.1, 1.1, 1.0) * geomSpecular;
}
