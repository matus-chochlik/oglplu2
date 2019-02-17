#version 330
uniform mat4 Projection;

layout(location = 0) in vec3 Position;
layout(location = 1) in float Occlusion;
layout(location = 2) in vec3 Normal;
layout(location = 3) in vec2 Coord;

out vec3 vertNormal;
out float vertOcclusion;
out vec2 vertCoord;

void main() {
    gl_Position = Projection * vec4(Position, 1.0);
	vertNormal = Normal;
	vertOcclusion = Occlusion;
	vertCoord = Coord * vec2(16.0, 8.0);
}
