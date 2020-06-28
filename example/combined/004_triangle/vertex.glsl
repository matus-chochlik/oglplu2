#version 140
in vec2 Position;
in vec3 Color;
out vec3 vertColor;
void main()
{
	gl_Position = vec4(Position, 0.0, 1.0);
   	vertColor = Color;
}

