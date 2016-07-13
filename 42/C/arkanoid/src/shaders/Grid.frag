#version 330 core
flat in int unit;
out vec4 color;
void main() {
	if (unit == 0)
		color = vec4(0.2, 0.2, 0.2, 1.0);
	else if (unit == -1)
		color = vec4(0.0, 0.1, 0.0, 1.0);
	else if (unit == 1)
		color = vec4(0.7, 0.1, 0.7, 1.0);
	else if (unit == 2)
		color = vec4(0.5, 0.2, 0.5, 1.0);
	else if (unit == 3)
		color = vec4(0.5, 0.5, 0.5, 1.0);
	else if (unit == 4) {
		color = vec4(0.85, 0.5, 0.15, 1.0);
	}
	else
		color = vec4(0.0, 0.0, 0.0, 1.0);
}
