#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

const vec2 ViewportDimensions = vec2(512, 512);

in vec3 vertNormal[3];

noperspective out vec3 geomDist;
out vec3 geomNormal;

void
main(void) {
    geomNormal = normalize(vertNormal[0] + vertNormal[1] + vertNormal[2]);

    vec2 ScreenPos[3];
    for(int i = 0; i != 3; ++i) {
	ScreenPos[i] =
	  ViewportDimensions * gl_in[i].gl_Position.xy / gl_in[i].gl_Position.w;
    }

    vec2 TmpVect[3];
    for(int i = 0; i != 3; ++i) {
	TmpVect[i] = ScreenPos[(i + 2) % 3] - ScreenPos[(i + 1) % 3];
    }

    const vec3 EdgeMask[3] =
      vec3[3](vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0));

    for(int v = 0; v < 3; ++v) {
	gl_Position = gl_in[v].gl_Position;

	float Dist = abs(TmpVect[(v + 1) % 3].x * TmpVect[(v + 2) % 3].y
			 - TmpVect[(v + 1) % 3].y * TmpVect[(v + 2) % 3].x)
		     / length(TmpVect[v]);
	vec3 DistVect = vec3(Dist, Dist, Dist);
	geomDist = EdgeMask[v] * DistVect;

	EmitVertex();
    }
    EndPrimitive();
}
