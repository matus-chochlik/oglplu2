#version 420

layout(binding = 0, offset = 0) uniform atomic_uint vc;
const float mult = 1.0/4.0;

in vec4 Position;

out vec3 vertColor;

void main() {
	gl_Position = Position;
   	vertColor = vec3(fract(atomicCounterIncrement(vc)*mult), 0.0, 0.0);
}
