#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

uniform mat4 Projection;

in vec3 vertColor[3];

out vec3 geomColor;
out vec3 geomNormal;
out vec3 geomCenter;
out vec3 geomCorner;

void main() {
    geomNormal = normalize(
      gl_in[0].gl_Position.xyz + gl_in[1].gl_Position.xyz +
      gl_in[2].gl_Position.xyz);
    geomCenter =
      0.33333 * (gl_in[0].gl_Position.xyz + gl_in[1].gl_Position.xyz +
                 gl_in[2].gl_Position.xyz);
    geomColor = 0.33333 * (vertColor[0] + vertColor[1] + vertColor[2]);

    for(int v = 0; v < 3; ++v) {
        geomCorner = gl_in[v].gl_Position.xyz;
        gl_Position = Projection * gl_in[v].gl_Position;
        EmitVertex();
    }
    EndPrimitive();
}
