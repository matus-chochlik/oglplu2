#version 140
in vec3 vertNormal;
in vec3 vertColor;
in vec3 vertLightDir;
in vec3 viewLightDir;
out vec3 fragColor;
uniform sampler2DRect DepthTexture;
const vec3 lightColor = vec3(1.0);

void main() {
    float lightDot = dot(vertLightDir, vertNormal);
    float diffuse = 0.25 + max(lightDot, 0.0) * 0.65;
    float specular = pow(max(lightDot + 0.03, 0.0), 64.0) * 0.5;

    ivec2 texelCoord = ivec2(gl_FragCoord.xy);
    float backZ = texelFetch(DepthTexture, texelCoord).x / gl_FragCoord.w;
    float frontZ = gl_FragCoord.z / gl_FragCoord.w;
    float translucence = pow(1.0 - sqrt(max(backZ - frontZ, 0.0)), 5.0);
    float transmission =
      translucence * mix(2.0 * (viewLightDir.z * 0.5 + 0.5), 0.5, 0.5);

    fragColor =
      vertColor * transmission + vertColor * diffuse + lightColor * specular;
}
