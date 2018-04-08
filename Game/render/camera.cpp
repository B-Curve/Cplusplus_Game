//
//  camera.cpp
//  Game
//
//  Created by Brandon Kervin on 4/8/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include "camera.hpp"

void Camera::update(GLFWwindow *window) {
    if(glfwGetKey(window, MOVE_FORWARD)) {
        position -= glm::normalize(glm::cross(right, worldUp)) * camSpeed;
    }
    if(glfwGetKey(window, MOVE_BACKWARD)) {
        position += glm::normalize(glm::cross(right, worldUp)) * camSpeed;
    }
    if(glfwGetKey(window, MOVE_LEFT)) position -= right * camSpeed;
    if(glfwGetKey(window, MOVE_RIGHT)) position += right * camSpeed;
    
    view = glm::lookAt(position + cameraHeight, position + direction + cameraHeight, up);
}

void Camera::updateMouse(const glm::vec2 &mousePos) {
    if(lastMouse == mousePos) return;
    float newX = mouseSensitivity * mousePos.x;
    float newY = mouseSensitivity * mousePos.y;
    
    rotation.x += newX;
    rotation.y += newY;
    
    if(rotation.y > 89.0f) rotation.y = 89.0f;
    if(rotation.y < -89.0f) rotation.y = -89.0f;
    
    glm::vec3 front;
    front.x = sin(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    front.y = sin(glm::radians(rotation.y));
    front.z = -cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
    direction = glm::normalize(front);
    right = glm::normalize(glm::cross(direction, worldUp));
    up = glm::normalize(glm::cross(right, direction));
    
    lastMouse = mousePos;
}
