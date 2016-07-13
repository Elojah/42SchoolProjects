#version 330 core
layout(location = 0) in vec3 vertexSpace;
out float zHeight;
uniform mat4	mvp;
void main() {
	gl_Position = mvp * vec4(vertexSpace, 1);
	zHeight = vertexSpace.y;
}
