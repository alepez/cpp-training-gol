#include "gol.hpp"

#include <algorithm>

namespace gol {

void update_grid(int* grid, int* grid_tmp, int w, int h) {
    for (int x = 0; x < w; ++x)
        for (int y = 0; y < h; ++y) {
            int adjacent_count = cell(grid, x - 1, y - 1)
                + cell(grid, x - 1, y + 0) + cell(grid, x - 1, y + 1)
                + cell(grid, x + 0, y - 1) + cell(grid, x + 0, y + 1)
                + cell(grid, x + 1, y - 1) + cell(grid, x + 1, y + 0)
                + cell(grid, x + 1, y + 1);
            cell(grid_tmp, x, y) = (adjacent_count == 3)
                || ((adjacent_count == 2 && cell(grid, x, y)));
        }
    std::copy(grid_tmp, grid_tmp + w * h, grid);
}

}  // namespace gol