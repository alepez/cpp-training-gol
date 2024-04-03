#pragma once

namespace gol {

class Grid;

class TerminalCanvas {
  public:
    TerminalCanvas(int w, int h, int scale);

    bool draw(Grid& grid);

  private:
    int w;
    int h;
    int scale;
};

}  // namespace gol