#version 430

in vec3 geomColor;
in vec3 geomNormal;
out vec3 fragColor;

const vec3 lightDir = normalize(vec3(1.0));

void main() {
	vec3 fragNormal = normalize(geomNormal);
	float ltdot = dot(fragNormal, lightDir);
	float ambient = 0.35;
	float diffuse = 0.65 * sqrt(max(ltdot+0.2, 0.0));
	float spec1 = 0.20 * sign(max(ltdot-0.99, 0.0));
	float spec2 = 0.15 * pow(max(ltdot+0.01, 0.0), 64.0);
    fragColor = geomColor * (ambient + diffuse) + vec3(1.0) * (spec1 + spec2);
}
