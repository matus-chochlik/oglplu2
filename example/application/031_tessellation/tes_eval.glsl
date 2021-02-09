#version 400

layout(triangles, equal_spacing, ccw) in;

layout (std140) uniform OffsetBlock {
	vec4 offset[16*16*16];
};
uniform mat4 CameraMatrix;

in vec3 tecoPosition[];
flat in int tecoInstanceId[];

out vec3 teevNormal;
out vec3 teevColor;
flat out int teevInstanceId;

void main() {
    vec3 p0 = gl_TessCoord.x * tecoPosition[0];
    vec3 p1 = gl_TessCoord.y * tecoPosition[1];
    vec3 p2 = gl_TessCoord.z * tecoPosition[2];

    vec4 tempPosition = vec4(normalize(p0+p1+p2), 0.0);
	teevInstanceId = tecoInstanceId[0];
    teevNormal = tempPosition.xyz;
	teevColor = normalize(abs(
		vec3(4.0, 4.0, 4.0)-
		offset[teevInstanceId].xyz
	));
	teevColor = mix(teevColor, vec3(1.0), 0.3);
	tempPosition = tempPosition + offset[tecoInstanceId[0]];
    tempPosition.w = 1.0;
    gl_Position = CameraMatrix * tempPosition;
}

