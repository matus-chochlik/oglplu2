#version 430
#define MB_COUNT 8

layout(local_size_x = 4, local_size_y = 4, local_size_z = 4) in;

uniform int PlaneCount;

struct FieldSample {
	vec3 color;
	float value;
};

layout (std430) buffer FieldBlock {
	FieldSample point[];
} field;

struct Metaball {
	vec3 majorAxis;
	float time;
	vec3 minorAxis;
	float speed;
	vec3 center;
	float radius;
	vec3 color;
};

layout (std430) buffer MetaballBlock {
	int count;
	Metaball param[MB_COUNT];
} metaballs;

int fieldIndex(ivec3 c) {
	ivec3 m = ivec3(1, PlaneCount, PlaneCount * PlaneCount);
	return m.x*c.x + m.y*c.y + m.z*c.z;
}

vec3 fieldCoord(ivec3 coord) {
	return vec3(coord) / float(PlaneCount);
}

FieldSample fieldSample(vec3 coord) {
	const float inorm = (1.0 / MB_COUNT);
	float eps = 0.001;
	FieldSample result;
	result.color = vec3(0.0);
	result.value = 0.0;
	for(int i = 0; i < MB_COUNT; ++i) {
		vec3 color  = metaballs.param[i].color;
		vec3 vect = metaballs.param[i].center - coord;
		float rad = metaballs.param[i].radius;
		float value = (pow(rad, 2.0) / (dot(vect, vect) + eps)) - 0.5;
		result.color += color * clamp(pow(exp(value-0.5), 2.0), 0.0, 1.0);
		result.value += value;
	}
	result.color *= inorm;
	result.value *= inorm;
	return result;
}

void main() {
	ivec3 coord = ivec3(gl_GlobalInvocationID);
	field.point[fieldIndex(coord)] = fieldSample(fieldCoord(coord));
}
