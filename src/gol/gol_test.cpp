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

//void update_grid(int* grid, int* grid_tmp, int w, int h);

std::string to_string(int* grid, int w, int h) {
    string result;
    result.reserve(w * h + h);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            result += grid[y * w + x] + '0';
        }
        result += "\n";
    }
    return result;
}

TEST_CASE("update_grid 3x3") {
    int grid[9] = {
        0, 0, 0,  //
        0, 1, 0,  //
        0, 0, 0,  //
    };

    int grid_tmp[9];

    gol::update_grid(grid, grid_tmp, 3, 3);

    Approvals::verify(to_string(grid, 3, 3));
}

TEST_CASE("update_grid 3x3, 3 iterations") {
    int grid[9] = {
        0, 0, 0,  //
        0, 1, 0,  //
        0, 0, 0,  //
    };

    int grid_tmp[9];

    for (int i = 0; i < 3; ++i) {
        gol::update_grid(grid, grid_tmp, 3, 3);
    }

    Approvals::verify(to_string(grid, 3, 3));
}