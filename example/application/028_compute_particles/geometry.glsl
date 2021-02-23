#version 430

layout (points) in;
layout (triangle_strip, max_vertices = 4) out;

uniform mat4 PerspectiveMatrix;

in vec3 vertColor[];
in float vertAge[];

out vec3 geomColor;

void main() {
	if(vertAge[0] <= 1.0) {
		geomColor = vertColor[0];
        float s = 0.5 * (1.0 + sin(sqrt(vertAge[0])*4.7123));
        float yo[2] = float[2](-1.0, 1.0);
        float xo[2] = float[2](-1.0, 1.0);
        for(int j = 0; j != 2; ++j) {
			for(int i = 0; i != 2; ++i) {
				float xoffs = xo[i] * s;
				float yoffs = yo[j] * s;
				gl_Position = PerspectiveMatrix * vec4(
					gl_in[0].gl_Position.x-xoffs,
					gl_in[0].gl_Position.y-yoffs,
					gl_in[0].gl_Position.z,
					1.0
				);
				EmitVertex();
			}
		}
		EndPrimitive();
	}
}

