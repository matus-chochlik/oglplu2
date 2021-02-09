#version 140

uniform vec2 ScreenSize;

in vec4 Position;
in vec2 TexCoord;

out vec2 vertTexCoord;

void main() {
	gl_Position = Position;
   	vertTexCoord = TexCoord * ScreenSize;
}

