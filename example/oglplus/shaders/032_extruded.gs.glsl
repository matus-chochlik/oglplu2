#version 330

layout(lines_adjacency) in;
layout(triangle_strip, max_vertices = 4) out;

uniform mat4 Projection;
uniform float Time;

in vec3 vertPosition[4];
in vec3 vertNormal[4];
in vec2 vertCoord[4];
out vec3 geomColor;

const float NPi = atan(1.0)*8.0;

void main()
{
	float Displacement =
		(1 + sin((vertCoord[0].x*NPi) + Time*5)) * 0.05+
		(1 + sin((vertCoord[0].y*NPi) + Time*3)) * 0.05;

	for(int i=0; i<4; ++i) {
   		vec3 Position = vertPosition[i] + vertNormal[i]*Displacement;
  		geomColor = abs(vertNormal[i]);
   		EmitVertex();
	}
	EndPrimitive();
}

