#version 420
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

layout(binding = 0, offset = 4) uniform atomic_uint gc;
const float mult = 1.0/2.0;

in vec3 vertColor[3];

out vec3 geomColor;

void main() {
	vec3 Color = vec3(0.0, fract(atomicCounterIncrement(gc)*mult), 0.0);

	for(int v=0; v!=3; ++v) {
   		gl_Position = gl_in[v].gl_Position;
   		geomColor = vertColor[v] + Color;
   		EmitVertex();
   	}
   	EndPrimitive();
}

