#include "Approvals.h"
#define APPROVALS_CATCH2_V3
#include <ApprovalTests.hpp>
#include <gol/gol.hpp>
#include <string>

using ApprovalTests::Approvals;
using std::back_inserter;
using std::string;
using std::to_string;
using std::transform;
using std::vector;

std::string to_string(int* grid, int w, int h) {
    std::string s;
    s.reserve(w * h + h);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            s += grid[y * w + x] ? 'X' : '.';
        }
        s += '\n';
    }
    return s;
}

TEST_CASE("gol grid update") {
    static constexpr int w = 5;
    static constexpr int h = 5;
    static constexpr int area = w * h;
    int grid[area] = {
        0, 0, 0, 0, 0,  //
        0, 0, 1, 0, 0,  //
        0, 1, 1, 1, 0,  //
        0, 0, 1, 0, 0,  //
        0, 0, 0, 0, 0,  //
    };
    int grid_tmp[area];
    gol::update_grid(grid, grid_tmp, w, h);
    Approvals::verify(to_string(grid, w, h));
}