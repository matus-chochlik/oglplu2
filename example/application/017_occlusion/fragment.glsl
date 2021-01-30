#version 140
in vec3 vertColor;
in vec3 vertNormal;
in vec3 vertViewDir;
in float vertOccl;
in float vertRough;

out vec3 fragColor;
const vec3 lightDir = normalize(vec3(7.0, 8.0, 9.0));

void main() {
    float ambient = 0.40 * vertOccl;
    float diffuse =
      0.60 * max(dot(lightDir, vertNormal), 0.0) * pow(vertOccl, 4.0);
    float specular = pow(
      clamp(dot(reflect(vertViewDir, vertNormal), lightDir) + 0.05, 0.0, 1.0) *
        pow(vertOccl * (1.0 - vertRough), 8.0),
      mix(64.0, 1.0, vertRough));
    fragColor = vertColor * (ambient + diffuse) + vec3(1.0) * specular;
}
