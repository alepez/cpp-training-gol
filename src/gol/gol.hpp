#pragma once

namespace gol {

#ifndef cell
#define cell(g, x, y) g[((h + y) % h) * w + ((w + x) % w)]
#endif

void update_grid(int* grid, int* grid_tmp, int w, int h);

}  // namespace gol
