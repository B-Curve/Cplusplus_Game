//
//  window.cpp
//  Game
//
//  Created by Brandon Kervin on 4/7/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "window.hpp"

static void mouse_callback(GLFWwindow *window, double xOff, double yOff);
static bool firstMouse = true;
static double lastX = 0, lastY = 0;
static float *xOffset, *yOffset;

Window::Window(unsigned int width, unsigned int height) {
    open = true;
    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW");
        open = false;
    }
    
    glfwWindowHint(GL_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    window = glfwCreateWindow(width, height, "Game", nullptr, nullptr);
    if(!window) {
        fprintf(stderr, "Failed to create window.");
        open = false;
        glfwTerminate();
    }
    
    glfwMakeContextCurrent(window);
    
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouse_callback);
    
    xOffset = &mouseX;
    yOffset = &mouseY;
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
    if(glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE)) {
        open = false;
    }
}

void Window::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 0, 1.0f);
}

static void mouse_callback(GLFWwindow *window, double xOff, double yOff) {
    if(firstMouse) {
        lastX = xOff;
        lastY = yOff;
        firstMouse = false;
    }
    
    *xOffset = xOff - lastX;
    *yOffset = lastY - yOff;
    
    lastX = xOff;
    lastY = yOff;
    
}









