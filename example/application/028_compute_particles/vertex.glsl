#version 430

layout (std430) buffer OffsetBlock {
	vec4 offset[];
} offsetBlock;

layout (std430) buffer AgeBlock {
    float age[];
} ageBlock;

uniform mat4 CameraMatrix;

in vec3 Origin;

out vec3 vertColor;
out float vertAge;

void main() {
	vec3 Offset = offsetBlock.offset[gl_InstanceID].xyz;
    gl_Position = CameraMatrix * vec4(Origin+Offset, 1.0);
	vertAge = ageBlock.age[gl_InstanceID];
    vertColor = mix(
		mix(
			vec3(1.2, 1.1, 1.0),
			vec3(1.0, 0.7, 0.5),
			min(sqrt(vertAge*3), 0.0)),
		vec3(0.1, 0.1, 0.1),
		sqrt(vertAge));
}
