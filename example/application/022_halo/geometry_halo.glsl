#version 150
layout(triangles_adjacency) in;
layout(triangle_strip, max_vertices = 12) out;

uniform mat4 View;
uniform mat4 Projection;

in vec3 vertCameraDir[];
in vec3 vertNormal[];

out vec3 geomCoord;

vec3 position(int i) {
	return gl_in[i].gl_Position.xyz;
}

vec3 normal(int i) {
	return vertNormal[i];
}

vec3 dir(int i) {
	return vertCameraDir[i];
}

vec3 triangleNormal(int a, int b, int c) {
	return normalize(cross(
		position(b) - position(c),
		position(a) - position(c)));
}

void makeVertex(int i, float u, float v, float w, float s) {
	float n = v * s;
	gl_Position = Projection * View * vec4(position(i) + normal(i) * n, 1.0);
	geomCoord = vec3(u, v, w);
	EmitVertex();
}

void processEdge(int a, int b, int c, int o) {
	vec3 da = dir(a);
	vec3 db = dir(b);
	vec3 ni = triangleNormal(a, b, c);
	vec3 no = triangleNormal(b, a, o);

	float nida = dot(ni, da);
	float nidb = dot(ni, db);
	float noda = dot(no, da);
	float nodb = dot(no, db);

	if((nida >= 0.0 || nidb >= 0.0) && (noda <= 0.0 || nodb <= 0.0)) {
		vec3 n = normalize(mix(ni, no, 0.5));
		float w = exp(-mix(mix(nida, nidb, 0.5),-mix(noda, nodb, 0.5), 0.5));
		float s = 0.2;
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

