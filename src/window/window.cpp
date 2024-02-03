#include <window.h>

Window::Window(std::string name, uint32_t width, uint32_t height)
    : mName{name}, mWidth{width}, mHeight{height}, mwindowStatus{false}
{
}

Window::~Window()
{
}

bool Window::init()
{
    std::cout << "Window Initialization Begin..!!" << std::endl;

    SDL_Init(SDL_INIT_EVERYTHING);

    mWindow = SDL_CreateWindow(mName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth, mHeight, 0);
    if (!mWindow)
    {
        // In case of error, print the error message
        std::cout << ("Could not create window: %s", SDL_GetError()) << std::endl;
        return mwindowStatus;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, 0);

    if (!mRenderer)
    {
        std::cout << ("Could not create renderer: %s", SDL_GetError()) << std::endl;
        return mwindowStatus;
    }

    mwindowStatus = true;

    return mwindowStatus;
}

void Window::cleanup()
{
    SDL_DestroyWindow(mWindow);
    // Quit SDL2
    SDL_Quit();

    std::cout << "Widnow terminated" << std::endl;
}


void Window::process()
{
    //Process inputs
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        mwindowStatus = false;
        break;
    case SDL_KEYDOWN:
        if(event.key.keysym.sym == SDLK_ESCAPE)
        {
            mwindowStatus = false;
        }
        break;
    
    default:
        break;
    }

}

void Window::update()
{

}

void Window::render()
{
    SDL_SetRenderDrawColor(mRenderer, 255, 120, 120, 225);
    SDL_RenderClear(mRenderer);

    SDL_RenderPresent(mRenderer);
}

uint32_t Window::getWidth()
{
    return mWidth;
}

uint32_t Window::getHeight()
{
    return mHeight;
}

void Window::setWidth(uint32_t width)
{
    mWidth = width;
}

void Window::setHeight(uint32_t height)
{
    mHeight = height;
}


bool Window::getWindowStatus()
{
    return mwindowStatus;
}