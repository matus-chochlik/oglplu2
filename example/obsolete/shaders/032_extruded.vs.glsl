#version 330

layout(location = 0) in vec3 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec2 Coord;

out vec3 vertPosition;
out vec3 vertNormal;
out vec2 vertCoord;

void main()
{
	vertPosition = Position;
   	vertNormal = Normal;
   	vertCoord = Coord;
}

