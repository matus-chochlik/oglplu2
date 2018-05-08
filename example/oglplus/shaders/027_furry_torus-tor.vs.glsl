#version 150

uniform mat4 CameraMatrix, ModelMatrix;

in vec4 Position;

void
main(void) {
    gl_Position = CameraMatrix * ModelMatrix * Position;
}
