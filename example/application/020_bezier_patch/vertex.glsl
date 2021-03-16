#version 400
uniform mat4 CameraMatrix;

in vec4 Position;
out vec4 vertPosition;

void main() {
	vertPosition = CameraMatrix * Position;
}

