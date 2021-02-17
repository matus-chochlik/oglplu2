#version 430

layout(binding = 0) uniform atomic_uint emitCounter;
layout(binding = 0) uniform atomic_uint randomCursor;
layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

layout (std430) buffer RandomBlock {
    float random[];
} randomBlock;

layout (std430) buffer OffsetBlock {
    vec3 offset[];
} offsetBlock;

layout (std430) buffer VelocityBlock {
    vec3 velocity[];
} velocityBlock;

layout (std430) buffer AgeBlock {
    float age[];
} ageBlock;

uniform vec3 emitPosition;
uniform float deltaTime;

float randomValue01() {
    uint index = atomicCounterIncrement(randomCursor) + gl_GlobalInvocationID.x;
    return randomBlock.random[index % randomBlock.random.length()];
}

float randomValueN() {
    return randomValue01() - 0.5;
}

vec3 randomVelocity() {
    return normalize(vec3(randomValueN(), randomValueN(), randomValueN()))*
        randomValue01();
}

void main() {
    uint particle = gl_GlobalInvocationID.x;
    velocityBlock.velocity[particle] *= (1.0 - 0.05 * deltaTime);
    offsetBlock.offset[particle] += velocityBlock.velocity[particle] * deltaTime;
    ageBlock.age[particle] += deltaTime * 0.25 * randomValue01();

    if(ageBlock.age[particle] >= 1.0) {
		uint maxEmit = uint(gl_NumWorkGroups.x * deltaTime * 0.11);
        if(atomicCounterIncrement(emitCounter) < maxEmit) {
            offsetBlock.offset[particle] = emitPosition;
            velocityBlock.velocity[particle] = randomVelocity();
            ageBlock.age[particle] = 0.0;
        }
    }
}
