#version 420 core
out vec4 FragColor; // x: red, y: green, z: blue, w: alpha

in vec4 vertexColor; // x: red, y: green, z: blue, w: alpha

void main()
{
    FragColor = vertexColor;
} 