//
//  window.hpp
//  Game
//
//  Created by Brandon Kervin on 4/7/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#ifndef window_hpp
#define window_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window {
public:
    Window(unsigned int width, unsigned int height);
    void update();
    void clear();
    inline GLFWwindow* getWindow() {
        return window;
    }
    inline bool isOpen() {
        return open;
    }
    inline glm::vec2 getMousePos() {
        return glm::vec2(mouseX, mouseY);
    }
private:
    GLFWwindow *window;
    bool open;
    float mouseX, mouseY;
};

#endif /* window_hpp */
