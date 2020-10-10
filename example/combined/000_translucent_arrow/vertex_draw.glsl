#version 140
in vec3 Position;
in vec3 Normal;
out vec3 vertNormal;
out vec3 vertColor;
out vec3 vertLightDir;
uniform mat4 Projection;
uniform vec3 LightPosition;

void main()
{
	gl_Position = Projection * vec4(Position, 1.0);
	vertNormal = Normal;
	vertColor = normalize(vec3(1) - mix(Normal, Position, 0.5));
	vertLightDir = normalize(LightPosition - Position);
}

