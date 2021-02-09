#version 140
uniform vec2 Offset;
uniform vec2 Scale;
in vec2 Position;
in vec2 Coord;
out vec2 vertCoord;

void main() {
    vertCoord = Coord * Scale + Offset;
    gl_Position = vec4(Position, 0.0, 1.0);
}
