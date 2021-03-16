#version 140
in vec3 Position;
uniform mat4 Camera;

void main() {
    gl_Position = Camera * vec4(Position, 1.0);
}
