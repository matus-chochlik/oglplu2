#version 150
in vec3 geomCoord;

out vec4 fragColor;

void main() {
	float strength =
		geomCoord.z*
		pow(1.0-geomCoord.y, 2.0)*
		(0.8+0.2*sin(3.14159 * geomCoord.x));
    fragColor = vec4(1.0, 0.8, 0.7, strength);
}
