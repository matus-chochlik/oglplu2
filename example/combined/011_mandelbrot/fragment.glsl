#version 140
uniform sampler1D gradient;
in vec2 vertCoord;
out vec4 fragColor;
void main()
{
	vec2 z = vec2(0.0, 0.0);
	vec2 c = vertCoord;
	int i = 0, max = 256;
	while((i != max) && (distance(z, c) < 2.0))
	{
		vec2 zn = vec2(
			z.x * z.x - z.y * z.y + c.x,
			2.0 * z.x * z.y + c.y
		);
		z = zn;
		++i;
	}
	float a = float(i)/float(max);
	fragColor = texture(gradient, a+sqrt(length(c))*0.1);
} 

