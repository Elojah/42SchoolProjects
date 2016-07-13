#version 330 core
in float zHeight;
out vec3 color;
void main() {
	if (zHeight < 15) {
		color = vec3(0.5 + zHeight / 100, 0.3 + zHeight / 100, 0.1);
	} else if (zHeight < 20) {
		color = vec3(0.1 + zHeight / 200, 0.4 + zHeight / 200, 0.2 + zHeight / 200);
	} else {
		color = vec3(1.0 - zHeight / 300, 1.0 - zHeight / 300, 1.0 - zHeight / 300);
	}
}
