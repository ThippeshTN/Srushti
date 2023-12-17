#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>
#include <SDL2/SDL.h>

class Window
{
private:
    int mWidth;
    int mHeight;
    std::string mName;
    SDL_Window* mWindow;

public:
    Window(std::string name, int width, int height);
    ~Window();
};

#endif //WINDOW_H_