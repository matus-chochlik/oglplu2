#version 150

uniform mat4 CameraMatrix, ModelMatrix;

in vec4 Position;

void main() {
    gl_Position = CameraMatrix * ModelMatrix * Position;
}
