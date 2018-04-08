//
//  main.cpp
//  Game
//
//  Created by Brandon Kervin on 4/7/18.
//  Copyright © 2018 Brandon Kervin. All rights reserved.
//

#include <iostream>
#include "window.hpp"
#include "render/shader.hpp"
#include "render/texture.hpp"
#include "render/cube.hpp"
#include "render/camera.hpp"

int main() {
    Window window(800, 600);
    Camera camera(glm::vec3(0, 0, 2.0f));
    
    Shader shader(DEFAULT);
    Texture texture(TX_BRICKS);
    Cube cube;
    
    while(window.isOpen()) {
        window.clear();
        
        camera.update(window.getWindow());
        camera.updateMouse(window.getMousePos());
        
        shader.bind();
        shader.setMat4(camera.getView(), "view");
        shader.setMat4(camera.getModel(), "model");
        shader.setMat4(camera.getProjection(), "projection");
        texture.bind(0);
        cube.draw();
        
        window.update();
    }
    
    return 0;
}
