//
//  camera.hpp
//  Game
//
//  Created by Brandon Kervin on 4/8/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef camera_hpp
#define camera_hpp

#define MOVE_FORWARD GLFW_KEY_W
#define MOVE_BACKWARD GLFW_KEY_S
#define MOVE_LEFT GLFW_KEY_A
#define MOVE_RIGHT GLFW_KEY_D

#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GLFW/glfw3.h>

class Camera {
public:
    Camera(const glm::vec3 &pos, const glm::vec3 dir = glm::vec3(0,0,-1)) {
        position = pos;
        direction = dir;
        right = glm::normalize(glm::cross(direction, worldUp));
        up = glm::normalize(glm::cross(right, direction));
        view = glm::lookAt(position, position + direction, up);
        projection = glm::perspective(glm::radians(50.0f), (800.0f/600.0f), 0.1f, 100.0f);
    }
    void update(GLFWwindow *window);
    void updateMouse(const glm::vec2 &mousePos);
    glm::vec3 position;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec2 rotation;
    glm::vec3 direction;
    inline glm::mat4 getView() const {
        return view;
    }
    inline glm::mat4 getModel() const {
        return model;
    }
    inline glm::mat4 getProjection() const {
        return projection;
    }
private:
    float camSpeed = 0.05f;
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view;
    glm::mat4 projection;
    glm::vec3 worldUp = glm::vec3(0,1,0);
    glm::vec2 lastMouse = glm::vec2(0,0);
    glm::vec3 cameraHeight = glm::vec3(0, 1.5f, 0);
    float mouseSensitivity = 0.1f;
};

#endif /* camera_hpp */
