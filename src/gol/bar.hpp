#pragma once

#include <SDL2/SDL.h>

namespace gol {

class Grid;

class SdlCanvas {
  public:
    SdlCanvas(int w, int h, int scale);

    ~SdlCanvas();

    bool draw(Grid& grid);

  private:
    SDL_Window* win;
    SDL_Event event;
};

}  // namespace gol