#include "gol.hpp"

namespace gol {

#define cell(g, x, y) g[((h + y) % h) * w + ((w + x) % w)]

void update_grid(int* grid, int* grid_tmp, int w, int h) {
    int x;
    int y;
    int adjacent_count;
    for (x = 0; x < w; ++x) {
        for (y = 0; y < h; ++y) {
            adjacent_count = cell(grid, x - 1, y - 1) + cell(grid, x - 1, y + 0)
                + cell(grid, x - 1, y + 1) + cell(grid, x + 0, y - 1)
                + cell(grid, x + 0, y + 1) + cell(grid, x + 1, y - 1)
                + cell(grid, x + 1, y + 0) + cell(grid, x + 1, y + 1);
            cell(grid_tmp, x, y) = adjacent_count == 3
                || (cell(grid, x, y) && adjacent_count == 2);
        }
    }
    for (x = 0; x < w * h; ++x) {
        grid[x] = grid_tmp[x];
    }
}

Grid::Grid(int w, int h) : w_(w), h_(h) {
    int area = w * h;
    data_.resize(area);
    tmp_data_.resize(area);
}

int* Grid::data() {
    return data_.data();
}

void Grid::update() {
    update_grid(data_.data(), tmp_data_.data(), w_, h_);
}

int& Grid::at(int x, int y) {
    return data_[y * w_ + x];
}

}  // namespace gol