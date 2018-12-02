#version 140
uniform vec2 Offset;
uniform vec2 Scale;
in vec2 Position;
out vec2 vertCoord;
void main() {
    vertCoord = Position * Scale + Offset;
    gl_Position = vec4(Position, 0.0, 1.0);
}
