#version 420

layout(binding = 0, offset = 8) uniform atomic_uint fc;
const float mult = 1.0/4096.0;

in vec3 geomColor;

out vec3 fragColor;

void main()
{
	vec3 Color = vec3(0.0, 0.0, sqrt(fract(atomicCounterIncrement(fc)*mult)));
   	fragColor = geomColor + Color;
}

