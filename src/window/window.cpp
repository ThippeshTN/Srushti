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

    mCOlourBufferTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, mWidth, mHeight);

    mColourBuffer = new Colour[sizeof(Colour) * mWidth * mHeight];

    return mwindowStatus;
}

void Window::cleanup()
{
    delete[] mColourBuffer;
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    // Quit SDL2
    SDL_Quit();

    std::cout << "Widnow terminated" << std::endl;
}

void Window::process()
{
    // Process inputs
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        mwindowStatus = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
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
    SDL_SetRenderDrawColor(mRenderer, 100, 100, 100, 225);
    SDL_RenderClear(mRenderer);

    SDL_UpdateTexture(mCOlourBufferTexture, NULL, mColourBuffer, sizeof(Colour) * mWidth);

    SDL_RenderCopy(mRenderer, mCOlourBufferTexture, NULL, NULL);
    

    Colour colour = Colour();
    clearColourBuffer(colour);
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

void Window::clearColourBuffer(Colour colour)
{
    for (uint32_t i = 0; i < mHeight; ++i)
    {
        for (uint32_t j = 0; j < mWidth; ++j)
        {
                mColourBuffer[(i * mWidth) + j] = colour;
        }
    }
}

void Window::setPixel(uint32_t posX, uint32_t posY,Colour colour)
{
    mColourBuffer[(posY * mWidth) + posX] = colour;
}

void Window::drawGrid(uint32_t offsetX, uint32_t offsetY, Colour colour)
{
    for (uint32_t i = 0; i < mWidth; ++i)
    {
        for (uint32_t j = 0; j < mHeight; ++j)
        {
            if(((i % offsetX) == 0) && ((j % offsetY) == 0) )
                setPixel(i, j, colour);
        }
    }
}

void Window::drawRect(uint32_t minX, uint32_t minY, uint32_t maxX, uint32_t maxY, Colour colour)
{
    for (uint32_t i = minX; i < maxX; ++i)
    {
        for (uint32_t j = minY; j < maxY; ++j)
        {
            setPixel(i, j, colour);
        }
    }
}
