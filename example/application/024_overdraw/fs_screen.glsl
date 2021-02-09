#version 140

uniform sampler2DRect DrawTex;

in vec2 vertTexCoord;

out vec4 fragColor;

void main() {
	vec2 drawData = texture(DrawTex, vertTexCoord).rg;
	float overdraw = drawData.x;
	float opacity = drawData.y;
	vec3 hiColor = vec3(1.0, 0.0, 0.0);
	vec3 loColor = vec3(0.0, 1.0, 0.0);
   	fragColor = vec4(
		mix(vec3(0.55), mix(loColor, hiColor, overdraw), opacity),
		opacity
	);
}

