#version 460

layout(binding = 0) uniform atomic_uint emitCounter;

layout (std430) buffer OffsetBlock {
	vec4 offset[];
} offsetBlock;

layout (std430) buffer AgeBlock {
    float age[];
} ageBlock;

uniform mat4 ProjectionMatrix;

in vec3 Origin;

out vec3 vertColor;
out float vertAge;

void main() {
	atomicCounterExchange(emitCounter, 0);
	vec3 Offset = offsetBlock.offset[gl_InstanceID].xyz;
    gl_Position = ProjectionMatrix * vec4(Origin+Offset, 1.0);
	vertAge = ageBlock.age[gl_InstanceID];
    vertColor = mix(vec3(1.0, 0.7, 0.5), vec3(0.25, 0.25, 0.25), sqrt(vertAge));
}
