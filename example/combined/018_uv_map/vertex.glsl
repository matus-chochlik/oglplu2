#version 140
in vec3 Position;
in vec3 Normal;
in vec2 WrapCoord;

out vec3 vertNormal;
out vec2 vertWrapCoord;

uniform mat4 Camera;

void main() {
    gl_Position = Camera * vec4(Position, 1.0);
	vertNormal = Normal;
    vertWrapCoord = WrapCoord;
}
