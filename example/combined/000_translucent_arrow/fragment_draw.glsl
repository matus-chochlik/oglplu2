#version 140
in vec3 vertNormal;
in vec3 vertColor;
in vec3 vertLightDir;
out vec3 fragColor;
const vec3 lightColor = vec3(1.0);

void main()
{
	float lightDot = dot(vertNormal, vertLightDir);
	float diffuse = 0.45 + max(0.0, lightDot)*0.75;
	float specular = pow(lightDot+0.03, 16.0);
	fragColor = vertColor*diffuse + lightColor*specular;
}

