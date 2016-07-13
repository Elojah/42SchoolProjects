#version 330 core
in float zHeight;
out vec4 color;
void main() {
	if (zHeight < 0.001f && zHeight > -0.001f) {
		color = vec4(1.0, 1.0, 1.0, 0.5);
	} else if (zHeight < 0.0f) {
		color = vec4(0.0, 0.0, 0.0, 0.0);
	} else {
		color = vec4(0.1, 0.1, 0.7 + zHeight / 100, 1.0);
	}
}
