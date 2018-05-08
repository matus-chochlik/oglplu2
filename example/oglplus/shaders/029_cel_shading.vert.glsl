#version 140

uniform mat4 Modelview;

in vec4 Position;
out vec3 vertColor;

void
main(void) {
    gl_Position = Position * Modelview;
    vertColor = normalize(vec3(1) - Position.xyz);
}
