#version 400
layout(quads, equal_spacing, ccw) in;
uniform mat4 PerspectiveMatrix;
patch in vec3 tecoPosition[16];

const mat4 BezierCoef = mat4(
	-1, 3,-3, 1,
	 3,-6, 3, 0,
	-3, 3, 0, 0,
	 1, 0, 0, 0 
);

mat4 Px, Py, Pz;

void main() {
	float u = gl_TessCoord.x, v = gl_TessCoord.y;

	for(int j = 0; j != 4; ++j) {
		for(int i = 0; i != 4; ++i) {
			int k = j * 4 + i;
			Px[j][i] = tecoPosition[k].x;
			Py[j][i] = tecoPosition[k].y;
			Pz[j][i] = tecoPosition[k].z;
		}
	}

	mat4 Cx = BezierCoef * Px * BezierCoef;
	mat4 Cy = BezierCoef * Py * BezierCoef;
	mat4 Cz = BezierCoef * Pz * BezierCoef;

	vec4 up = vec4(u*u*u, u*u, u, 1);
	vec4 vp = vec4(v*v*v, v*v, v, 1);

	vec4 tempPosition = vec4(
		dot(Cx * vp, up),
		dot(Cy * vp, up), 
		dot(Cz * vp, up),
		1.0);

	gl_Position = PerspectiveMatrix * tempPosition;
}

