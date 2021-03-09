#version 430
#define MB_COUNT 24

layout(local_size_x = MB_COUNT) in;

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

uint hash(uint u) {
    u += (u << 10u);
    u ^= (u >>  6u);
    u += (u <<  3u);
    u ^= (u >> 11u);
    u += (u << 15u);
    return u;
}

shared float cursor = 345.678;

float random() {
	const uint mant = 0x007FFFFFu;
	const uint one  = 0x3F800000u;
   
	float f = cursor;
	cursor += 1.618 ;
	uint h = hash(floatBitsToUint(f));
	h &= mant;
	h |= one;
	
	return uintBitsToFloat(h) - 1.0;
}

vec3 randomVec() {
	return vec3(random(), random(), random());
}

void init() {
	if(metaballs.count < MB_COUNT) {
		if(gl_LocalInvocationIndex == 0u) {
			while(metaballs.count < MB_COUNT) {
				int i = metaballs.count++;
				vec3 axis = randomVec();
				axis[i % 3] = 2.0 * float(i % 2);
				axis = normalize(axis);
				metaballs.param[i].majorAxis = axis * 0.5;
				metaballs.param[i].time = 0.0;
				metaballs.param[i].minorAxis = axis.yxz * 0.25;
				metaballs.param[i].speed = 0.2 + random() * 0.15;
				metaballs.param[i].center = vec3(0.0);
				metaballs.param[i].radius = 0.1 + random() * 0.1;
				vec3 color = randomVec();
				color[i % 3] = 2.0 * float(i % 2);
				metaballs.param[i].color = normalize(color) * 1.414;
			}
		}
	}
}

void update() {
	uint i = gl_LocalInvocationIndex;
	metaballs.param[i].time += 0.05;
	float p = metaballs.param[i].time * metaballs.param[i].speed;
	vec3 z = vec3(0.0);
	vec3 o = vec3(1.0);
	vec3 r = vec3(metaballs.param[i].radius);
	vec3 c = vec3(0.5)-
		cos(p) * metaballs.param[i].majorAxis-
		sin(p) * metaballs.param[i].minorAxis;

	c -= max(c + r - o, z);
	c += max(r - c, z);

	metaballs.param[i].center = c;

}

void main() {
	init();
	update();
}
