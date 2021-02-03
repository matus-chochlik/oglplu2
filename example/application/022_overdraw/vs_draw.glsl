#version 140
uniform mat4 Camera;

layout (std140) uniform OffsetBlock {
	vec4 Offset[16*16*16];
};

in vec3 Position;

void main() {
	gl_Position = Camera * vec4(Position+Offset[gl_InstanceID].xyz, 1.0);
}

