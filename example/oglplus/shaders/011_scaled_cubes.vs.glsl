#version 140
uniform mat4 Projection;
uniform vec3 Center;
uniform float Time;
uniform float Pick;

in vec3 Position;
in vec3 Pivot;
in vec3 BoxCoord;

out vec3 vertColor;

void main() {
	vec3 Dir = Position - Pivot;
	float Scale = clamp(sin(length(Pivot-Center)-Time * 3)+0.25, 0.2, 0.7);
	vertColor = BoxCoord * mix(0.9, 1.3, Pick);
    gl_Position = Projection * vec4(Pivot + Dir * Scale, 1.0);
}
