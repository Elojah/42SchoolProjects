#version 330 core
layout(location = 0) in vec2 vertex;
void main() {
	gl_Position.xy = (vertex * 2.0 - 1.0);
	gl_Position.z = -0.01;
	gl_Position.w = 1.0;
}
