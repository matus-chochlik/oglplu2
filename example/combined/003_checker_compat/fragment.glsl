#version 140
out vec3 fragColor;
void main() {
    vec2 co = gl_TexCoord[0].xy * vec2(8.0);
    float ck = mod(mod(int(co.x), 2) + mod(int(co.y), 2), 2);
    fragColor = mix(vec3(0.0), gl_Color.rgb, ck);
}
