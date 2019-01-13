#version 330

uniform vec3 LightDirection;

in vec3 geomNormal;
in vec3 geomColor;
in float geomLight;

out vec3 fragColor;

void main()
{
	float DotL = dot(geomNormal, LightDirection);
	float Ambient = 0.3;
	float Diffuse = max(DotL, 0.0);
	float Emission = geomLight;
	float Specular = pow(DotL, 32.0);

	fragColor = geomColor * (Ambient + Diffuse + Emission) +
		vec3(1.0, 1.0, 0.95) * Specular;
}

