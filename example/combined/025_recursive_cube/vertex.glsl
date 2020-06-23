#version 140

uniform mat4 Projection;
uniform mat4 Modelview;
uniform vec3 LightPos;

in vec4 Position;
in vec3 Normal;
in vec2 TexCoord;

out vec3 vertNormal;
out vec3 vertLightDir;
out vec2 vertTexCoord;

void main() {
    gl_Position = Modelview * Position;
    vertNormal = mat3(Modelview) * Normal;
    vertLightDir = LightPos - gl_Position.xyz;
    vertTexCoord = TexCoord;
    gl_Position = Projection * gl_Position;
}
