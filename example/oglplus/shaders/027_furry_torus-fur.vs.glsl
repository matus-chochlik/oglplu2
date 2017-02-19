#version 150

uniform mat4 NewModelMatrix, OldModelMatrix;
uniform sampler2D FurTex;

in vec4 Position;
in vec3 Normal;
in vec2 TexCoord;

out vec3 vertOffset;
out vec3 vertNormal;
out vec3 vertColor;

void main(void)
{
	gl_Position = 
		NewModelMatrix * 
		Position;
	vertOffset = (
		gl_Position - 
		OldModelMatrix * 
		Position
	).xyz;
	vertNormal = mat3(NewModelMatrix) * Normal;
	vertColor = texture(FurTex, TexCoord).rgb;
}
