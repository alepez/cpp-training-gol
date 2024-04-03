#include "foo.hpp"

#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <thread>

#include "gol.hpp"

using namespace std::chrono_literals;

namespace gol {

TerminalCanvas::TerminalCanvas(int w, int h, int scale) :
    w(w), h(h), scale(scale) {
#ifdef _WIN32
    system("cls");
    system("color 0F");
#else
    system("clear");
#endif
}

bool TerminalCanvas::draw(Grid& grid) {
    int x;
    int y;
    for (y = 0; y < h; ++y) {
        for (x = 0; x < w; ++x)
            printf(grid.at(x, y) ? "X" : " ");
        printf("\n");
    }
    std::this_thread::sleep_for(40ms);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    return true;
}

}  // namespace gol