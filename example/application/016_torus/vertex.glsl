#version 140
in vec3 Position;
in vec3 Normal;
in vec2 TexCoord;
out vec3 vertNormal;
out vec2 vertCoord;
uniform mat4 Camera;
void main() {
    gl_Position = Camera * vec4(Position, 1.0);
    vertNormal = mat3(Camera) * Normal;
    vertCoord = TexCoord * vec2(36.0, 12.0);
}
