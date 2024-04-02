add_library(gol STATIC)

target_include_directories(gol
        PUBLIC ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(gol
        PUBLIC spdlog::spdlog
        PUBLIC fmt::fmt
)

# Enable all warnings and treat them as errors, but only for the library
target_compile_options(gol
        PRIVATE -Wall
        PRIVATE -Wpedantic
        PRIVATE -Wextra
        PRIVATE -Werror
        PRIVATE -Wno-unused-parameter
)

add_executable(gol_test)

target_include_directories(gol_test
        PRIVATE ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(gol_test
        PRIVATE Catch2::Catch2WithMain
        PRIVATE ApprovalTests::ApprovalTests
        PRIVATE gol
)

function(add_module name)
    target_sources(gol PRIVATE ${name}.cpp)
    target_sources(gol_test PRIVATE ${name}_test.cpp)
endfunction()

add_module(foo)
add_module(bar)
add_module(gol)
