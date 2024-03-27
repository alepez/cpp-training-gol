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

add_executable(game_of_life
        main.cpp
)

target_link_libraries(game_of_life
        PRIVATE spdlog::spdlog
        PRIVATE fmt::fmt
        PRIVATE gol
)

find_package(SDL2)

if (NOT SDL2_FOUND)
    message(WARNING "SDL2 not found, disabling SDL2 support")
else ()
    target_link_libraries(game_of_life
            PRIVATE SDL2
    )
    target_compile_definitions(game_of_life
            PRIVATE WITH_SDL
    )
endif ()

set(CMAKE_CXX_STANDARD 17)

enable_testing()