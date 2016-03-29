#include "glew.h"

//std include
#include <iostream>

//SFML include
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

//OpenGL include
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

//loacl includes
#include "world.h"

#define WORLD_WI 800
#define WORLD_HE 600

World* world = new World(WORLD_WI, WORLD_HE);

void build_world()
{
    world->build();
    world->render_world();
    std::cout<<"All work done."<<std::endl;
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WORLD_WI, WORLD_HE), "Ray/Path tracing", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // load resources, initialize the OpenGL states, ...
    // Build world
    build_world();

    // run the main loop
    bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.setActive();

        // draw...
        sf::Texture texture;
        texture.create(WORLD_WI,WORLD_HE);
        sf::Sprite sprite(texture);
        texture.update(world->_pixels);

        window.draw(sprite);

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}
