#version 140

uniform vec2 Offset;
uniform vec2 Scale;

in vec4 Position;
in vec2 TexCoord;

out vec2 vertTexCoord;

void main() {
    gl_Position = Position;
    vertTexCoord = Scale * TexCoord + Offset;
}
