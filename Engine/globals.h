/**
 * name: globals.h
 * purpose: Hold any global values and libraries that are frequently accessed.
 * date_created: 24-07-2025
 * date_modified: 28-07-2025
 */
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define VERTEX_SHADER_PATH "./shaders/vertex_0.glsl"
#define FRAGMENT_SHADER_PATH "./shaders/fragment_0.glsl"

// Define at runtime
extern float delta;


// Predefiened
static float vertices[] = {
    0.5f, 0.5f, 0.0f,   // top right
    0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f   // top left
};

static unsigned int indices[] = {
    // note that we start from 0!
    0, 1, 3, // first Triangle
    1, 2, 3  // second Triangle
};