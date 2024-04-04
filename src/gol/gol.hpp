#pragma once

namespace gol {

#ifndef cell
#define cell(g, x, y) g[((h + y) % h) * w + ((w + x) % w)]
#endif

void update_grid(int* grid, int* grid_tmp, int w, int h);

struct Input {
    int w { 10 };
    int h { 10 };
    int seed { 123 };
    int scale { 1 };
    int canvas_type { 0 };
    int repeat { -1 };
};

Input parse_input(int argc, const char** argv);

}  // namespace gol
