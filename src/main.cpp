/// What the hell is this?
///
/// This is a poorly written Conway's Game of Life implementation in C++.
///
/// It uses SDL2 for rendering, but can be compiled without it.
/// When compiled without SDL2, it will print the game of life grid to the console.
/// The grid is a 2D array of integers, where 0 is dead and 1 is alive.
/// The grid is updated every 40ms.
/// The grid size, seed, and scale can be set as command line arguments.
/// The grid size is set to 10x10 by default if SDL2 is not available.
///
/// Why is this poorly written?
///
/// No comments, poor error handling, no function decomposition, no separation of concerns, no encapsulation,
/// no abstraction, no tests, no documentation, no design patterns, no best practices.
/// What you have: global variables, magic numbers, hard-coded values, preprocessor directives, bad naming.
/// Just a single file with a single function that does everything with global variables.
///
/// Your job is to refactor this code to make it better.

#ifdef WITH_SDL
    #include <gol/bar.hpp>
#else
    #include <gol/foo.hpp>
#endif

#include <cstdlib>

#include "gol/gol.hpp"

using namespace gol;

int main(int argc, const char** argv) {
    int running = 1;

    int high_res = 0;
#ifdef WITH_SDL
    high_res = 1;
#endif

    int w = argc > 1 ? atoi(argv[1]) : (high_res ? 640 : 10);
    int h = argc > 2 ? atoi(argv[2]) : (high_res ? 480 : 10);
    int seed = argc > 3 ? atoi(argv[3]) : 123;
    int scale = argc > 4 ? atoi(argv[4]) : 1;
    srand(seed);

    Grid grid(w, h);

    if (seed != 0) {
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                grid.data()[((h + y) % h) * w + ((w + x) % w)] = rand() % 2;
            }
        }
    }

#ifdef WITH_SDL
    SdlCanvas canvas(w, h, scale);
#else
    TerminalCanvas canvas(w, h, scale);
#endif

    while (running) {
        grid.update();
        running = canvas.draw(grid);
    }
    return 0;
}
