#version 140

uniform vec2 Scale;
uniform sampler2D Tex;

in vec2 vertTexCoord;

out vec3 fragColor;

const vec2 offs[9] = vec2[9](
  vec2(-1, -1),
  vec2(-1, 0),
  vec2(-1, 1),
  vec2(0, -1),
  vec2(0, 0),
  vec2(0, 1),
  vec2(1, -1),
  vec2(1, 0),
  vec2(1, 1));

vec2 point(vec2 tc, vec2 ofs) {
    vec2 cc = floor(tc + ofs);
    return cc + texture(Tex, cc / textureSize(Tex, 0)).xy;
}

float dist(vec2 tc, vec2 ofs) {
    vec2 cp = point(tc, ofs);
    return distance(tc, cp);
}

vec3 worley(vec2 tc) {
	float ds[9];
    for(int c = 0; c < 9; ++c) {
		ds[c] = dist(tc, offs[c]);
    }
	float md = ds[0];
	int mc = 0;
    for(int c = 1; c < 9; ++c) {
		if(md > ds[c]) {
			md = ds[c];
			mc = c;
		}
    }
	float nd = 4;
    for(int c = 0; c < 9; ++c) {
		if(c != mc) {
			nd = min(nd, ds[c]);
		}
    }
    return vec3(nd-md);
}

void main() {
    fragColor = worley(vertTexCoord);
}
