#version 330 core
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 vertexUV;
uniform mat4	vp;
out vec2		UV;
void main() {
	gl_Position = vp * vec4(vertex, 1.0);
	UV = vertexUV;
}
