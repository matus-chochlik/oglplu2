#version 400
layout(vertices = 16) out;

in vec4 vertPosition[];
patch out vec3 tecoPosition[16];

void main() {

	if(gl_InvocationID == 0) {
		float dist = 0.0;
		for(int v=0; v<16; ++v) {
			dist += vertPosition[v].z;
		}
		dist /= 16.0;

   		int tl = 1+int(1000 / pow(dist, 2));
  
		gl_TessLevelInner[0] = tl;
		gl_TessLevelInner[1] = tl;
		gl_TessLevelOuter[0] = tl;
		gl_TessLevelOuter[1] = tl;
		gl_TessLevelOuter[2] = tl;
		gl_TessLevelOuter[3] = tl;
	}
	tecoPosition[gl_InvocationID] = vertPosition[gl_InvocationID].xyz;
}

