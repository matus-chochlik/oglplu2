#version 150
#define PointCount 4

layout(points) in;
layout(line_strip, max_vertices = PointCount) out;

uniform vec3 LightPosition;
uniform mat4 CameraMatrix;
uniform float Time;
const float FurLength = 0.45;
const float SegPart = 1.0 / (PointCount - 1);
const float SegLen = FurLength * SegPart;

in vec3 vertOffset[];
in vec3 vertNormal[];
in vec3 vertColor[];

out vec3 geomNormal;
out vec3 geomFurDir;
out vec3 geomLightDir;
out vec3 geomColor;
out float geomFurPart;
void main(void)
{
	geomColor = vertColor[0];
	geomNormal = vertNormal[0];
	geomFurPart = 0.0;
	vec4 VertPos = gl_in[0].gl_Position;
	float Wind = sin(4.0*(VertPos.x+Time));

	for(int i=0; i!=PointCount; ++i)
	{
		geomLightDir = normalize(LightPosition - VertPos.xyz);
		geomFurDir = normalize(
			vertNormal[0] * 0.1 - 
			vertOffset[0] * i*i*0.3 + 
			vec3(Wind*i*i*0.01, 0.0, 0.0)
		);
		gl_Position = CameraMatrix * VertPos;
		EmitVertex();
		geomFurPart += SegPart;
		VertPos += vec4(geomFurDir, 0.0) * SegLen;
	}
	EndPrimitive();
}

