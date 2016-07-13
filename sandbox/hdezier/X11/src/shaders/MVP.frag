#version 330 core
in float zHeight;
out vec3 color;
void main() {
	if (zHeight < 0) {
		color = vec3(0.1, 0.1, 0.1);
	} else if (zHeight < 4) {
		color = vec3(0.1, 0.1, 0.7);
	} else if (zHeight < 4.5) {
		color = vec3(0.7, 0.8, 0.9 + 0.05 * zHeight);
	} else if (zHeight < 10) {
		color = vec3(0.4 + 0.01 * zHeight, 0.3, 0.1);
	} else if (zHeight < 18) {
		color = vec3(0.2 + 0.01 * zHeight, 0.7, 0.2);
	} else {
		color = vec3(1.0, 1.0, 1.0);
	}
}
