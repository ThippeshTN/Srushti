#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>
#include <SDL2/SDL.h>

struct Colour
{
    Colour()
        : r{0}, g{0}, b{0}, a{0} {

                            };

    Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
        : r{red}, g{green}, b{blue}, a{alpha}
    {
    }

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

class Window
{
private:
    uint32_t mWidth;
    uint32_t mHeight;
    std::string mName;
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    SDL_Texture *mCOlourBufferTexture;
    bool mwindowStatus;
    Colour *mColourBuffer;

public:
    Window(std::string name, uint32_t width, uint32_t height);
    ~Window();

    // Creating and initializing the window
    bool init();

    // Clenaing up and deleting the window
    void cleanup();

    // Handling input data
    void process();

    // Updating the data
    void update();

    // Rendering pixels on winodw
    void render();

    uint32_t getWidth();
    void setWidth(uint32_t width);

    uint32_t getHeight();
    void setHeight(uint32_t height);

    bool getWindowStatus();

    void setPixel(uint32_t posX, uint32_t posY, Colour colour);
    void drawGrid(uint32_t offsetX, uint32_t offsetY, Colour colour);
    void drawRect(uint32_t minX, uint32_t minY, uint32_t maxX, uint32_t maxY, Colour Colour);

private:
    void clearColourBuffer(Colour colour);
};

#endif // WINDOW_H_