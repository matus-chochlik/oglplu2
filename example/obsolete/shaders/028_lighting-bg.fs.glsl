#version 140

in vec3 vertCoord;
out vec3 fragColor;

float lines(float c) {
    return pow(2 * abs(c - floor(c + 0.5)), 64);
}

float grid(vec3 c) {
    return lines(c.x) + lines(c.y) + lines(c.z);
}

void main() {
    fragColor = mix(
      vec3(0.25, 0.25, 0.2),
      vec3(0),
      grid(vertCoord) + grid(vertCoord * 5.0) * 0.75);
}
