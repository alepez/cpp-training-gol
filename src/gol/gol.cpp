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

Input parse_input(int argc, const char** argv) {
    Input input;
    input.w = argc > 1 ? atoi(argv[1]) : 10;
    input.h = argc > 2 ? atoi(argv[2]) : 10;
    input.seed = argc > 3 ? atoi(argv[3]) : 123;
    input.scale = argc > 4 ? atoi(argv[4]) : 1;
    input.canvas_type = argc > 5 ? atoi(argv[5]) : 0;
    input.repeat = argc > 6 ? atoi(argv[6]) : -1;
    return input;
}

}  // namespace gol