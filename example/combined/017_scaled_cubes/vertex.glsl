#version 140
uniform mat4 Camera;
uniform vec3 Center;
uniform float Time;

in vec3 Position;
in vec3 Pivot;
in vec3 Coord;

out vec3 vertColor;

void main()
{
	vec3 Dir = Position - Pivot;
	float Dist = length(Pivot-Center);
	float Scale = clamp(sin(Dist-Time * 3)+0.25, 0.2, 0.7);
	gl_Position = Camera * vec4(Pivot + Dir * Scale, 1.0);
	vertColor = mix(Coord, vec3(1.4), exp(-Dist));
}

