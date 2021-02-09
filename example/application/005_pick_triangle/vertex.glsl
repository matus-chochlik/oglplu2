#version 140
uniform float Highlight;
in vec2 Position;
out vec3 vertColor;
const vec3 Red = vec3(1.0, 0.2, 0.2);
const vec3 Grn = vec3(0.2, 1.0, 0.2);

void main() {
    gl_Position = vec4(Position, 0.0, 1.0);
    vertColor = mix(Red, Grn, Highlight);
}
