#version 140
in vec3 Position;
in vec3 Color;
out vec3 vertColor;
uniform mat4 Camera;
void main() {
    gl_Position = Camera * vec4(Position, 1.0);
    vertColor = Color;
}
