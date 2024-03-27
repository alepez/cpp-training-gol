cmake_minimum_required(VERSION 3.12)

cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0079 NEW)

project(game_of_life
        VERSION 0.1.0
        DESCRIPTION "Game of Life"
        LANGUAGES CXX
)

add_subdirectory(cmake)
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 17)

enable_testing()