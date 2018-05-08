#version 330

uniform mat4 Projection;

layout(location = 0) in vec3 Position;

out vec3 vertCoord;

void
main(void) {
    gl_Position = Projection * vec4(Position * 50, 1);
    vertCoord = Position * 10;
}
