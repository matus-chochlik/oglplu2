#version 140
in vec3 vertNormal;
in vec2 vertCoord;
out vec3 fragColor;
void main()
{
	float ck = mod(mod(int(vertCoord.x), 2) + mod(int(vertCoord.y), 2), 2);
	float bl = pow(1.1 - abs(vertNormal.z), 2.0) * 0.7;
	float fl = abs(vertNormal.z) * 0.5;
	fragColor = vec3(ck * fl + bl);
}

