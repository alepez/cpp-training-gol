#pragma once

#include <vector>

namespace gol {

class Grid {
  public:
    Grid(int w, int h);

    int* data();

    void update();

    int& at(int x, int y);

    int width() const { return w_; }
    int height() const { return h_; }

  private:
    int w_;
    int h_;
    std::vector<int> data_;
    std::vector<int> tmp_data_;
};

}  // namespace gol
