#version 150

in vec3 geomNormal;
in vec3 geomFurDir;
in vec3 geomLightDir;
in vec3 geomColor;
in float geomFurPart;

out vec3 fragColor;
const vec3 LightColor = vec3(1.0, 1.0, 1.0);

void main(void)
{
	const float Ambient = 0.3;
	float FurLight = 1.0 - abs(dot(geomFurDir, geomLightDir));
	float ShapeLight = max(dot(geomNormal, geomLightDir)+0.4, 0.0);
	float Diffuse = FurLight * ShapeLight;
	vec3 Color = mix(vec3(0.2, 0.2, 0.2), geomColor, geomFurPart);
	fragColor = 
		Ambient * Color +
		sqrt(Diffuse) * geomFurPart * Color;
}

