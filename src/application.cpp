#include <iostream>

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#include "window.h"


int main(int argc, char* argv[])
{
    std::cout << "Project Srushti..!!" << std::endl;

    Window window("Srushti", 1280, 720);
    std::cout << (window.init() ? "SUCCESS" : "FAILED") << std::endl;

    while (window.getWindowStatus())
    {
        window.process();
        window.drawGrid(10, 10, Colour(50, 50, 50, 255));
        window.drawRect(200, 200, 500, 500, Colour(0XFF, 0X50, 0X00, 0XFF));
        window.render();
    }
    
    window.cleanup();

    return 0;
}