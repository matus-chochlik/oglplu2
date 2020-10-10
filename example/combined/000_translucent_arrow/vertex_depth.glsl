#version 140
in vec3 Position;
uniform mat4 Projection;

void main()
{
	gl_Position = Projection * vec4(Position, 1.0);
}

