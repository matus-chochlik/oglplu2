#version 330

layout(lines) in;
layout(triangle_strip, max_vertices = 4) out;

void main() {
	vec4 offs = vec4(0.02, 0.01, 0.0, 0.0);
   	gl_Position = gl_in[0].gl_Position - offs;
   	EmitVertex();
   	gl_Position = gl_in[0].gl_Position + offs;
   	EmitVertex();
   	gl_Position = gl_in[1].gl_Position - offs;
   	EmitVertex();
   	gl_Position = gl_in[1].gl_Position + offs;
   	EmitVertex();
   	EndPrimitive();
}

