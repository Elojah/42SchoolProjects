#version 330 core
layout(location = 0) in vec3 vertexCoord;
out float color_vertex;
void main() {
	gl_Position.xy = vertexCoord.xy;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	color_vertex = vertexCoord.z;
}
