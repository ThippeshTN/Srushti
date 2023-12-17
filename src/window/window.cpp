#include <window.h>

Window::Window(std::string name, int width, int height)
    : mName{name}, mWidth{width}, mHeight{height}
{
    std::cout << "Window Initialization Begin..!!" << std::endl;

    SDL_Init(SDL_INIT_VIDEO);

    mWindow = SDL_CreateWindow(mName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_OPENGL);
    if (mWindow == NULL)
    {
        // In case of error, print the error message
        printf("Could not create window: %s\n", SDL_GetError());
    }
}


Window::~Window()
{
    SDL_DestroyWindow(mWindow);
    // Quit SDL2
    SDL_Quit();

    std::cout << "Widnow terminated" << std::endl;
}