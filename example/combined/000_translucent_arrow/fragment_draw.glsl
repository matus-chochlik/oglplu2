#version 140
in vec3 vertNormal;
in vec3 vertColor;
in vec3 vertLightDir;
out vec3 fragColor;
const vec3 lightColor = vec3(1.0);

void main()
{
	float lightDot = max(dot(vertLightDir, vertNormal), 0.0);
	float diffuse = 0.45 + lightDot*0.75;
	float specular = pow(lightDot+0.1, 16.0);
	fragColor = vertColor*diffuse + lightColor*specular;
}

