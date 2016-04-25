#version 140
uniform sampler1D gradient;
in vec2 vertCoord;
out vec4 fragColor;

vec2 f(vec2 n)
{
	return vec2(
		n.x*n.x*n.x - 3.0*n.x*n.y*n.y - 1.0,
		-n.y*n.y*n.y + 3.0*n.x*n.x*n.y
	);
}

vec2 df(vec2 n)
{
	return 3.0 * vec2(
		n.x*n.x - n.y*n.y,
		2.0 * n.x * n.y
	);
}

vec2 cdiv(vec2 a, vec2 b)
{
	float d = dot(b, b);
	if(d == 0.0) return a;
	else return vec2(
		(a.x*b.x + a.y*b.y) / d,
		(a.y*b.x - a.x*b.y) / d 
	);
}

void main(void)
{
	vec2 z = vertCoord;
	int i, max = 128;
	for(i = 0; i < max; ++i)
	{
		vec2 zn = z - cdiv(f(z), df(z));
		if(distance(zn, z) < 0.00001) break;
		z = zn;
	}
	fragColor = texture(gradient, float(i) / float(max));
}
