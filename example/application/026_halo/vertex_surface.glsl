#version 150
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

in vec3 Position;
in vec3 Normal;

out vec3 vertNormal;

void main() {
    gl_Position = Projection * View * Model * vec4(Position, 1.0);
    vertNormal = mat3(View * Model) * Normal;
}
