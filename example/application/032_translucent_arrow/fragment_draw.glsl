#version 140
in vec3 vertNormal;
in vec3 vertColor;
in vec3 vertViewDir;
in vec3 vertLightDir;
in vec3 viewLightDir;
out vec3 fragColor;
uniform sampler2DRect DepthTexture;
const vec3 lightColor = vec3(1.0);

void main() {
    float diffuse = 0.25 + max(dot(vertLightDir, vertNormal), 0.0) * 0.65;
    float specular =
      0.5 *
      pow(
        clamp(
          dot(vertLightDir, reflect(vertViewDir, vertNormal)) + 0.02, 0.0, 1.0),
        64.0);

    ivec2 texelCoord = ivec2(gl_FragCoord.xy);
    float backZ = texelFetch(DepthTexture, texelCoord).x / gl_FragCoord.w;
    float frontZ = gl_FragCoord.z / gl_FragCoord.w;
    float translucence = pow(1.0 - sqrt(max(backZ - frontZ, 0.0)), 5.0);
    float transmission =
      translucence * mix(2.0 * (viewLightDir.z * 0.5 + 0.5), 0.5, 0.5);

    fragColor =
      vertColor * transmission + vertColor * diffuse + lightColor * specular;
}
