#version 150

layout(triangles_adjacency) in;
layout(triangle_strip, max_vertices = 3) out;

uniform vec2 viewportDimensions;

in vec3 vertPosition[6];
in vec3 vertNormal[6];
in vec2 vertCoord[6];

noperspective out vec3 geomDist;
out vec3 geomNormal;
out vec2 geomCoord;

vec2[3] edgeVector() {
    vec2 screenPos[3];
    for(int i = 0; i < 3; ++i) {
        screenPos[i] = viewportDimensions *
		gl_in[i * 2].gl_Position.xy / gl_in[i * 2].gl_Position.w;
    }

    vec2 edgeVect[3];
    for(int i = 0; i < 3; ++i) {
        edgeVect[i] = screenPos[(i + 2) % 3] - screenPos[(i + 1) % 3];
    }
	return edgeVect;
}

vec3 triangleNormal(int a, int b, int c) {
	return normalize(cross(
		vertPosition[b] - vertPosition[c],
		vertPosition[a] - vertPosition[c]));
}

float edgeCoef(int a, int b, int c, int o) {
	vec3 ni = triangleNormal(a, b, c);
	vec3 no = triangleNormal(b, a, o);
	return dot(ni, no) < 0.1 ? 1.0 : 16.0;
}

void main() {
	vec2 edgeVect[3] = edgeVector();
    vec3 edgeMask[3] = vec3[3](
		vec3(edgeCoef(2, 4, 0, 3), 0.0, 0.0),
		vec3(0.0, edgeCoef(4, 0, 2, 5), 0.0),
		vec3(0.0, 0.0, edgeCoef(0, 2, 4, 1)));

    for(int v = 0; v < 3; ++v) {

        float dist = abs(
            edgeVect[(v + 1) % 3].x * edgeVect[(v + 2) % 3].y-
            edgeVect[(v + 1) % 3].y * edgeVect[(v + 2) % 3].x)/
            length(edgeVect[v]);

        vec3 distVect = vec3(dist, dist, dist);

        gl_Position = gl_in[v * 2].gl_Position;
        geomNormal = vertNormal[v * 2];
        geomCoord = vertCoord[v * 2];
        geomDist = edgeMask[v] * distVect;

        EmitVertex();
    }
    EndPrimitive();
}
