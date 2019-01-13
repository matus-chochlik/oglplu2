#version 330

layout(lines_adjacency) in;
layout(triangle_strip, max_vertices = 20) out;

uniform mat4 Projection;
uniform float Time;

in vec3 vertPosition[4];
in vec3 vertNormal[4];
in vec2 vertCoord[4];

out vec3 geomNormal;
out vec3 geomColor;
out float geomLight;

const float NPi = atan(1.0)*16.0;
const ivec4 sideIdx[4] = ivec4[4](
	ivec4(0, 2, 1, 3),
	ivec4(2, 3, 0, 1),
	ivec4(3, 1, 2, 0),
	ivec4(1, 0, 3, 2)
);
const vec3 edgeColor[2] = vec3[2](
	vec3(1.0, 1.0, 0.2),
	vec3(0.9, 0.7, 0.2)
);
const float edgeLight[2] = float[2](1.0, 0.2);

void main() {
	vec2 faceCoord = 0.25*(
		vertCoord[0] +
		vertCoord[1] +
		vertCoord[2] +
		vertCoord[3]
	);

	float DispStrength = (1.0-exp(-abs(0.5-faceCoord.y)*4.0))*0.3;
	float Displacement =
		max(pow(sin((faceCoord.x*NPi) + Time*0.618), 3), 0)*
		max(pow(cos((faceCoord.y*NPi) + Time*1.618), 3), 0);

	vec3 extrPosition[4];
	for(int i=0; i<4; ++i) {
   		extrPosition[i] =
			vertPosition[i] +
			vertNormal[i] * Displacement * DispStrength;
	}

	geomColor = vec3(0.2);
	geomLight = 0.0;

	for(int i=0; i<4; ++i) {
		gl_Position = Projection * vec4(extrPosition[i], 1.0);
  		geomNormal = vertNormal[i];
   		EmitVertex();
	}
	EndPrimitive();

	for(int s=0; s<4; ++s) {
		for(int e=0; e<2; ++e) {
			int i = sideIdx[s][e+0];
			int j = sideIdx[s][e+2];

			geomColor = edgeColor[0];
			geomLight = edgeLight[0];
			gl_Position = Projection * vec4(vertPosition[i], 1.0);
			geomNormal = normalize(vertPosition[i]-vertPosition[j]);
			EmitVertex();

			geomColor = edgeColor[1];
			geomLight = edgeLight[1];
			gl_Position = Projection * vec4(extrPosition[i], 1.0);
			geomNormal = normalize(extrPosition[i]-extrPosition[j]);
			EmitVertex();
		}

		EndPrimitive();
	}
}

