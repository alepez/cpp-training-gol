#include "bar.hpp"

#include <SDL2/SDL.h>

#include <exception>

#include "gol.hpp"

namespace gol {

SdlCanvas::SdlCanvas(int w, int h, int scale) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::terminate();
    }

    win = SDL_CreateWindow(
        "Conway's Game of Life",
        0,
        0,
        scale * w,
        scale * h,
        4
    );

    if (!win) {
        std::terminate();
    }
}

bool SdlCanvas::draw(Grid& grid) {
    int x;
    int y;
    bool running = true;
    for (x = 0; x < SDL_GetWindowSurface(win)->w; ++x)
        for (y = 0; y < SDL_GetWindowSurface(win)->h; ++y)
            ((int*)(SDL_GetWindowSurface(win)->pixels)
            )[x + y * SDL_GetWindowSurface(win)->w] = 0x00FFFFFF
                * grid.at(
                    x / (SDL_GetWindowSurface(win)->w / grid.width()),
                    y / (SDL_GetWindowSurface(win)->h / grid.height())
                );
    SDL_UpdateWindowSurface(win);
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            running = false;
    SDL_Delay(40);
    return running;
}

SdlCanvas::~SdlCanvas() {
    SDL_DestroyWindow(win);
    SDL_Quit();
}

}  // namespace gol