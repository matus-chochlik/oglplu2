#version 150
layout(triangles_adjacency) in;
layout(triangle_strip, max_vertices = 12) out;

uniform mat4 Projection;

in vec3 vertPosition[];
in vec3 vertNormal[];

out vec3 geomCoord;

vec3 triangleNormal(int a, int b, int c) {
	return cross(
		normalize(vertPosition[a] - vertPosition[c]),
		normalize(vertPosition[b] - vertPosition[c]));
}

void makeVertex(int i, float u, float v, float w, float s) {
	float n = v * s;
	gl_Position = Projection * vec4(vertPosition[i] + vertNormal[i]*n, 1.0);
	geomCoord = vec3(u, v, w);
	EmitVertex();
}

void processEdge(int a, int b, int c, int o) {
	vec3 ni = triangleNormal(a, b, c);
	vec3 no = triangleNormal(b, a, o);

	if(no.z > 0.0 && ni.z < 0.0) {
		float c = exp(ni.z);
		float k = distance(gl_in[a].gl_Position.xy, gl_in[b].gl_Position.xy);
		float l = distance(vertPosition[a], vertPosition[b]);
		float w = sqrt(c * k * 2.0);
		float s = sqrt(c * l * 2.0);
		makeVertex(a, 0.0, 0.0, w, s);
		makeVertex(a, 0.0, 1.0, w, s);
		makeVertex(b, 1.0, 0.0, w, s);
		makeVertex(b, 1.0, 1.0, w, s);
		EndPrimitive();
	}
}

void main() {
	processEdge(0, 2, 4, 1);
	processEdge(2, 4, 0, 3);
	processEdge(4, 0, 2, 5);
}

