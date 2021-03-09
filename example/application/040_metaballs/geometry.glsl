#version 430

layout (lines_adjacency) in;
layout (triangle_strip, max_vertices = 16) out;

uniform mat4 PerspectiveMatrix;

layout (std430) buffer ConfigsBlock {
	uvec4 edgeVertices[];
} configs;

in vec3 vertColor[];
in float vertValue[];
in vec3 vertGradient[];
in int vertInside[];

out vec3 geomColor;
out vec3 geomNormal;

float findParam(uint i0, uint i1) {
	float d =  vertValue[i1] - vertValue[i0];
	return d == 0.0 ? 0.5 : -vertValue[i0] / d;
}

void makeVertex(uint i0, uint i1) {
	float param = findParam(i0, i1);
	gl_Position = PerspectiveMatrix * mix(
		gl_in[i0].gl_Position,
		gl_in[i1].gl_Position,
		param);

	geomColor = normalize(mix(vertColor[i0], vertColor[i1], param));
	geomNormal = mix(vertGradient[i0], vertGradient[i1], param);
	EmitVertex();
}

void makeSurface(uvec4 vi0, uvec4 vi1, int count) {
	for(int i = 0; i < count; ++i) {
		makeVertex(vi0[i], vi1[i]);
	}
	EndPrimitive();
}

void processTetrahedron() {
	ivec4 mask  = ivec4(1);
	ivec4 inside = ivec4(
		vertInside[0],
		vertInside[1],
		vertInside[2],
		vertInside[3]
	);
	int cutCount = int(dot(inside, mask)) % 4;

	if(cutCount != 0) {
		int configIndex = int(dot(inside, ivec4(16, 8, 4, 2)));
		makeSurface(
			configs.edgeVertices[configIndex+0],
			configs.edgeVertices[configIndex+1],
			4 - cutCount % 2);
	}
}

void main() {
	processTetrahedron();
}

