#ifndef WINDOW_H_
#define WINDOW_H_
#include <iostream>
#include <SDL2/SDL.h>

class Window
{
private:
    uint32_t mWidth;
    uint32_t mHeight;
    std::string mName;
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    bool mwindowStatus;

public:
    Window(std::string name, uint32_t width, uint32_t height);
    ~Window();

    //Creating and initializing the window
    bool init();

    //Clenaing up and deleting the window
    void cleanup();

    //Handling input data
    void process();

    //Updating the data
    void update();

    //Rendering pixels on winodw
    void render();


    uint32_t getWidth();
    void setWidth(uint32_t width);

    uint32_t getHeight();
    void setHeight(uint32_t height);

    bool getWindowStatus();

};

#endif //WINDOW_H_