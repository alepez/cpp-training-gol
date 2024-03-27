Include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.13.0
)

FetchContent_MakeAvailable(spdlog)

target_compile_definitions(spdlog PUBLIC SPDLOG_FMT_EXTERNAL)
target_link_libraries(spdlog PRIVATE fmt::fmt)
