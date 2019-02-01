#version 330

layout(lines_adjacency) in;
layout(triangle_strip, max_vertices = 20) out;

uniform mat4 Projection;
uniform vec3 LightDirection;

in vec3 vertPosition[4];
in vec3 vertNormal[4];
in vec2 vertCoord[4];

out vec3 geomColor;
out float geomAmbient;
out float geomEmission;
out float geomDiffuse;
out float geomSpecular;

const float NPi = atan(1.0)*12.0;
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
const float edgeLight[2] = float[2](1.2, 0.3);

void main() {
	vec2 faceCoord = vec2(0.0);
	vec3 faceNormal = vec3(0.0);

	for(int i=0; i<4; ++i) {
		faceCoord += vertCoord[i];
		faceNormal += vertNormal[i];
	}
	faceCoord *= 0.25;
	faceNormal *= 0.25;

	float Arg = abs(dot(LightDirection, faceNormal));
	float Occ = exp(-abs(0.5-faceCoord.y)*4.0);
	geomAmbient = Occ * 0.3;
	float DispStrength = Occ * 0.9;
	float Displacement = pow(Arg, 32.0);

	vec3 extrPosition[4];
	for(int i=0; i<4; ++i) {
   		extrPosition[i] =
			vertPosition[i] +
			vertNormal[i] * Displacement * DispStrength;
	}

	geomColor = normalize(vec3(1)+faceNormal);
	geomEmission = Displacement * 3.0;
	float LightDot = dot(faceNormal, LightDirection);
	geomDiffuse = pow(max(LightDot, 0.1), 2.0);
	geomSpecular = pow(max(LightDot, 0.0), 32.0);

	for(int i=0; i<4; ++i) {
		gl_Position = Projection * vec4(extrPosition[i], 1.0);
   		EmitVertex();
	}
	EndPrimitive();

	geomDiffuse = 0.0;
	geomSpecular = 0.0;

	for(int s=0; s<4; ++s) {
		for(int e=0; e<2; ++e) {
			int i = sideIdx[s][e+0];
			int j = sideIdx[s][e+2];

			geomColor = edgeColor[0];
			geomEmission = edgeLight[0] * Displacement;
			gl_Position = Projection * vec4(vertPosition[i], 1.0);
			EmitVertex();

			geomColor = edgeColor[1];
			geomEmission = edgeLight[1] * Displacement;
			gl_Position = Projection * vec4(extrPosition[i], 1.0);
			EmitVertex();
		}

		EndPrimitive();
	}
}

