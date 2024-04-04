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
using namespace gol;

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

TEST_CASE("update_grid 3x3, lines of three") {
    int grid[9] = {
        0, 0, 0,  //
        1, 1, 1,  //
        0, 0, 0,  //
    };

    int grid_tmp[9];

    gol::update_grid(grid, grid_tmp, 3, 3);

    Approvals::verify(to_string(grid, 3, 3));
}

TEST_CASE("update_grid 5x5, lines of three") {
    int grid[25] = {
        0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0,  //
        0, 1, 1, 1, 0,  //
        0, 0, 0, 0, 0,  //
        0, 0, 0, 0, 0,  //
    };

    int grid_tmp[25];

    gol::update_grid(grid, grid_tmp, 5, 5);

    Approvals::verify(to_string(grid, 5, 5));
}

TEST_CASE("update_grid 30x30") {
    // clang-format off
    int grid[30 * 30] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //
    };
    // clang-format on

    int grid_tmp[30 * 30];

    gol::update_grid(grid, grid_tmp, 30, 30);

    Approvals::verify(to_string(grid, 30, 30));
}

TEST_CASE("cli argument parse, default") {
    const char* argv[] = {
        "gol",
    };
    auto input = parse_input(1, argv);

    Input default_input;
    REQUIRE(input.w == default_input.w);
    REQUIRE(input.h == default_input.h);
    REQUIRE(input.seed == default_input.seed);
    REQUIRE(input.scale == default_input.scale);
    REQUIRE(input.canvas_type == default_input.canvas_type);
    REQUIRE(input.repeat == default_input.repeat);
}

TEST_CASE("cli argument parse, all arguments") {
    const char* argv[] = {
        "gol", "10", "20", "30", "40", "50", "60",
    };

    auto input = parse_input(7, argv);

    REQUIRE(input.w == 10);
    REQUIRE(input.h == 20);
    REQUIRE(input.seed == 30);
    REQUIRE(input.scale == 40);
    REQUIRE(input.canvas_type == 50);
    REQUIRE(input.repeat == 60);
}