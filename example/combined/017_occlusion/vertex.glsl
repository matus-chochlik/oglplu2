#version 140
in vec3 Position;
in vec3 Color;
in vec3 Normal;
in float Occlusion;

out vec3 vertColor;
out vec3 vertNormal;
out vec3 vertViewDir;
out float vertOccl;

uniform mat4 Camera;

void main() {
    gl_Position = Camera * vec4(Position, 1.0);
    vertColor = Color;
    vertNormal = Normal;
	vec3 cameraLoc = (vec4(0.0, 0.0, 0.0, 1.0) * Camera).xyz;
	vertViewDir = normalize(cameraLoc - Position);
    vertOccl = Occlusion;
}
