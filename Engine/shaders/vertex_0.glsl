#version 420 core
layout (location = 0) in vec3 aPos;

out vec4 vertexColor; // x: red, y: green, z: blue, w: alpha

void main()
{
    gl_Position = vec4(aPos, 1.0);
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
    // vertexColor = vec4(vertexColor);
}