#version 330 core
layout(location = 0) in vec2 vertex;
layout(location = 1) in int unit_type;
flat out int unit;
void main() {
	gl_Position.xy = vertex * 2.0 - 1.0;
	gl_Position.z = 0.0;
	gl_Position.w = 1.0;
	unit = unit_type;
}
