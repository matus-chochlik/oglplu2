#version 150
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

in vec3 Position;
in vec3 Normal;
in vec2 Coord;

out vec3 vertPosition;
out vec3 vertNormal;
out vec2 vertCoord;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0);
	vertPosition = Position;
    vertNormal = mat3(View * Model) * Normal;
	vertCoord = Coord * 4.0;
}
