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
    #include <SDL2/SDL.h>
#endif

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <gol/bar.hpp>
#include <gol/foo.hpp>
#include <gol/gol.hpp>
#include <thread>

using namespace std::chrono_literals;
using namespace gol;

#ifdef WITH_SDL
SDL_Window* win;
SDL_Event event;
bool sdl_should_run = true;
#endif

void canvas_sdl_init(int w, int h, int scale);
void canvas_sdl_draw(int* grid, int w, int h);
bool canvas_sdl_should_run();
void canvas_sdl_teardown();

void canvas_terminal_init();
void canvas_terminal_draw(int* grid, int w, int h);

int main(int argc, const char** argv) {
    int grid[1'000'000], grid_tmp[1'000'000];

    Input input = parse_input(argc, argv);
    auto [w, h, seed, scale, canvas_type, repeat] = input;

    if (canvas_type == 1) {
        canvas_sdl_init(w, h, scale);
    } else {
        canvas_terminal_init();
    }

    srand(seed);
    if (seed != 0)
        for (int x = 0; x < w; ++x)
            for (int y = 0; y < h; ++y)
                grid[((h + y) % h) * w + ((w + x) % w)] = rand() % 2;

    int counter = 0;
    bool running = true;

    while (running) {
        if (repeat > 0) {
            counter += 1;
            if (counter >= repeat) {
                break;
            }
        }

        update_grid(grid, grid_tmp, w, h);

        if (canvas_type == 1) {
            canvas_sdl_draw(grid, w, h);
        } else {
            canvas_terminal_draw(grid, w, h);
        }

        if (canvas_type == 1) {
            running = canvas_sdl_should_run();
        }
    }

    if (canvas_type == 1) {
        canvas_sdl_teardown();
    }

    return 0;
}

void canvas_sdl_teardown() {
#ifdef WITH_SDL
    SDL_DestroyWindow(win);
    SDL_Quit();
#endif
}

void canvas_terminal_draw(int* grid, int w, int h) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x)
            printf(cell(grid, x, y) ? "X" : " ");
        printf("\n");
    }
    std::this_thread::sleep_for(40ms);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void canvas_sdl_draw(int* grid, int w, int h) {
#ifdef WITH_SDL
    for (int x = 0; x < SDL_GetWindowSurface(win)->w; ++x)
        for (int y = 0; y < SDL_GetWindowSurface(win)->h; ++y)
            ((int*)(SDL_GetWindowSurface(win)->pixels)
            )[x + y * SDL_GetWindowSurface(win)->w] = 0x00FFFFFF
                * cell(grid,
                       x / (SDL_GetWindowSurface(win)->w / w),
                       y / (SDL_GetWindowSurface(win)->h / h));
    SDL_UpdateWindowSurface(win);
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
            sdl_should_run = false;
    SDL_Delay(40);
#endif
}

void canvas_sdl_init(int w, int h, int scale) {
#ifdef WITH_SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exit(-1);
    win = SDL_CreateWindow(
        "Conway's Game of Life",
        0,
        0,
        scale * w,
        scale * h,
        4
    );
    if (!win)
        exit(-1);
#endif
}

void canvas_terminal_init() {
#ifdef _WIN32
    system("cls");
    system("color 0F");
#else
    system("clear");
#endif
}

bool canvas_sdl_should_run() {
    return sdl_should_run;
}