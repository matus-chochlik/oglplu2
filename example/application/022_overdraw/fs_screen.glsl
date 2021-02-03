#version 140

uniform sampler1D Palette;
uniform sampler2DRect Tex;

in vec2 vertTexCoord;

out vec4 fragColor;

void main() {
	float Overdraw = texture(Tex, vertTexCoord).r;
   	fragColor = texture(Palette, Overdraw);
}

