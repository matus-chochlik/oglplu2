#version 140

uniform mat4 Projection;

in vec4 Position;
out vec3 vertNormal;

void
main(void) {
    gl_Position = Projection * Position;
    vertNormal = Position.xyz;
}
