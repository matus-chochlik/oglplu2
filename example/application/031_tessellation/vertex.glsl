#version 400

layout (std140) uniform OffsetBlock {
	vec4 offset[16*16*16];
};
uniform vec3 CameraPosition;

in vec3 Position;

out vec3 vertPosition;
out float vertDistance;
flat out int vertInstanceId;

void main() {
    vertPosition = Position;
    vertDistance = length(
		CameraPosition - (vertPosition + offset[gl_InstanceID].xyz));
	vertInstanceId = gl_InstanceID;
}
