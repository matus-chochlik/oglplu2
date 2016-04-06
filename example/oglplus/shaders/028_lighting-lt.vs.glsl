#version 330

const vec3 LightPos[5] = vec3[5](
	vec3( 0, -100, 0),
	vec3( 10, 10, 20),
	vec3( 10, 20,-10),
	vec3(-20, 10,-20),
	vec3(-10, 20, 10) 
);

uniform mat4 Projection, Modelview;

layout (location = 0) in vec4 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec2 TCoord;

out vec3 vertNormal;
out vec2 vertTCoord;
out float vertOccl;
out vec3 vertLightDir[5];

void main(void)
{
	gl_Position = Modelview*Position;
	vertNormal = mat3(Modelview)*Normal;
	vertTCoord = TCoord*vec2(32,8);
	vertOccl = 0.5*(1+sqrt(2*abs(0.5-TCoord.y)));
	for(int i=0; i<5; ++i)
	{
		vertLightDir[i]=LightPos[i]-gl_Position.xyz;
	}
	gl_Position = Projection*gl_Position;
}
