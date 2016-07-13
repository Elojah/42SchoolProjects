#version 330 core
out vec3 color;
in float color_vertex;
void main() {
	color = vec3(color_vertex, color_vertex, color_vertex);
}
