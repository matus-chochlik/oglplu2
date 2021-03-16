#version 140
in vec3 Position;
in vec3 Normal;
out vec3 vertNormal;
out vec3 vertColor;
out vec3 vertViewDir;
out vec3 vertLightDir;
out vec3 viewLightDir;
uniform mat4 Camera;
uniform vec3 LightPosition;

void main() {
    gl_Position = Camera * vec4(Position, 1.0);
    vertNormal = Normal;
    vertColor = normalize(vec3(1) - mix(Normal, Position, 0.5));
	vec3 cameraLoc = (vec4(0.0, 0.0, 0.0, 1.0) * Camera).xyz;
	vertViewDir = normalize(cameraLoc - Position);
    vertLightDir = normalize(LightPosition - Position);
    viewLightDir = normalize((Camera * vec4(LightPosition, 1.0)).xyz);
}
