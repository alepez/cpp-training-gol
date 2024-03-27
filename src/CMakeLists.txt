add_subdirectory(gol)

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