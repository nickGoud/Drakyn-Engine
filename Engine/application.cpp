/**
 * Name: application.cpp
 * Date created: 20-06-2025
 * Last modified: 20-06-2025
 */

#include "application.h"

#include <stdio.h>

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
    init();
    main_loop();
    cleanup();
}

void Application::init() 
{
    // Set Render Context
    // printf("Hello World!!!\n");
}

void Application::main_loop()
{
    //while(window_open) {}
}

void Application::cleanup()
{
}
