#include <iostream>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include "window.h"


int main(int argc, char* argv[])
{
    std::cout << "Project Srushti..!!" << std::endl;

    Window window("Srushti", 640, 480);
    std::cout << (window.init() ? "SUCCESS" : "FAILED") << std::endl;

    while (window.getWindowStatus())
    {
        window.process();
        // window.setPidraxel(10,10, Colour(255, 100, 0, 255));
        window.drawGrid(10, 10, Colour(255, 100, 0, 255));
        window.render();
    }
    
    window.cleanup();

    return 0;
}