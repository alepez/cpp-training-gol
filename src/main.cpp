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
#endif

#include <cstdlib>

#include "gol/gol.hpp"

using namespace gol;

int running = 1, w, h, seed, x, y, scale, adjacent_count, high_res = 0;

int main(int argc, const char** argv) {
#ifdef WITH_SDL
    high_res = 1;
#else
    #ifdef _WIN32
    system("cls");
    system("color 0F");
    #else
    system("clear");
    #endif
#endif
    w = argc > 1 ? atoi(argv[1]) : (high_res ? 640 : 10);
    h = argc > 2 ? atoi(argv[2]) : (high_res ? 480 : 10);
    seed = argc > 3 ? atoi(argv[3]) : 123;
    scale = argc > 4 ? atoi(argv[4]) : 1;
    srand(seed);

    Grid grid(w, h);

    if (seed != 0)
        for (x = 0; x < w; ++x)
            for (y = 0; y < h; ++y)
                grid.data()[((h + y) % h) * w + ((w + x) % w)] = rand() % 2;
#ifdef WITH_SDL
    SdlCanvas canvas(w, h, scale);
#endif
    while (running) {
        grid.update();
#ifdef WITH_SDL
        running = canvas.draw(grid);
#else
        for (y = 0; y < h; ++y) {
            for (x = 0; x < w; ++x)
                printf(cell(grid, x, y) ? "X" : " ");
            printf("\n");
        }
        std::this_thread::sleep_for(40ms);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
#endif
    }
#ifdef WITH_SDL

#endif
    return 0;
}
