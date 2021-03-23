#version 150
uniform mat4 Model;
uniform vec3 CameraPos;

in vec3 Position;
in vec3 Normal;

out vec3 vertCameraDir;
out vec3 vertNormal;

void main() {
    gl_Position = Model * vec4(Position, 1.0);
	vertCameraDir = normalize(CameraPos - gl_Position.xyz);
    vertNormal = mat3(Model) * Normal;
}
