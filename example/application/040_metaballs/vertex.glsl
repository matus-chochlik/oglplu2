#version 430

uniform mat4 CameraMatrix;
uniform int PlaneCount;
uniform int DivCount;

struct FieldSample {
	vec3 color;
	float value;
	vec3 gradient;
};

layout (std430) buffer FieldBlock {
	FieldSample point[];
} field;

in ivec3 Corner;
out vec3 vertColor;
out float vertValue;
out vec3 vertGradient;
out int vertInside;

ivec3 cornerCoord() {
	int x = gl_InstanceID % DivCount; 
	int y = (gl_InstanceID / DivCount) % DivCount; 
	int z = gl_InstanceID / (DivCount * DivCount);
	return ivec3(x, y, z) + Corner;
}

int fieldIndex(ivec3 c) {
	ivec3 m = ivec3(1, PlaneCount, PlaneCount * PlaneCount);
	return m.x*c.x + m.y*c.y + m.z*c.z;
}

vec3 cornerPosition(ivec3 coord) {
	return ((vec3(coord) / float(DivCount-1)) - vec3(0.5)) * 10.0;
}

void main() {
	ivec3 coord = cornerCoord();
    gl_Position = CameraMatrix * vec4(cornerPosition(coord), 1.0);
	FieldSample point = field.point[fieldIndex(coord)];
	vertColor = point.color;
	vertValue = point.value;
	vertGradient = point.gradient;
	vertInside = (vertValue  >= 0.0) ? 1 : 0;
}
