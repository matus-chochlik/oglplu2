#version 400

layout(vertices = 3) out;

in vec3 vertPosition[];
in float vertDistance[];
flat in int vertInstanceId[];

out vec3 tecoPosition[];
flat out int tecoInstanceId[];

int tessLevel(float dist) {
    return 1+int(32.0 / (dist+0.1));
}

void main() {
    tecoPosition[gl_InvocationID] = vertPosition[gl_InvocationID];
    tecoInstanceId[gl_InvocationID] = vertInstanceId[gl_InvocationID];

    if(gl_InvocationID == 0) {
        gl_TessLevelInner[0] = tessLevel((
            vertDistance[0]+
            vertDistance[1]+
            vertDistance[2]
        )*0.333);
        gl_TessLevelOuter[0] = tessLevel((
            vertDistance[1]+
            vertDistance[2]
        )*0.5);
        gl_TessLevelOuter[1] = tessLevel((
            vertDistance[2]+
            vertDistance[0]
        )*0.5);
        gl_TessLevelOuter[2] = tessLevel((
            vertDistance[0]+
            vertDistance[1]
        )*0.5);
    }
}

