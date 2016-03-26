#version 140

uniform vec2 Scale;
uniform sampler2D Tex;

in vec2 vertTexCoord;

out vec3 fragColor;

const vec2 offs[9] = vec2[9](
	vec2(-1,-1),
	vec2(-1, 0),
	vec2(-1, 1),
	vec2( 0,-1),
	vec2( 0, 0),
	vec2( 0, 1),
	vec2( 1,-1),
	vec2( 1, 0),
	vec2( 1, 1) 
);

float dist(vec2 tc, vec2 ofs)
{
	vec2 cc = floor(tc+ofs);
	vec2 cp = texture(Tex, cc/textureSize(Tex, 0)).xy;
	return distance(tc, cc+cp);
}

vec3 point_color(vec2 tc, vec2 ofs)
{
	vec2 cc = floor(tc+ofs);
	return texture(Tex, cc/textureSize(Tex, 0)).rgb;
}

vec3 voronoi(vec2 tc)
{
	float md = 2.0;
	int mc = 9;
	for(int c=0; c<9; ++c)
	{
		float d = dist(tc, offs[c]);
		if(md > d)
		{
			md = d;
			mc = c;
		}
	}
	return mix(
		point_color(tc, offs[mc])*mix(1.4, 0.5, md),
		vec3(0, 0, 0),
		pow(exp(1-md*128/sqrt(length(Scale))), 2.0)
	);
}

void main(void)
{
	fragColor = voronoi(vertTexCoord);
}

