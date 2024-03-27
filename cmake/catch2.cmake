Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.2
)

FetchContent_MakeAvailable(Catch2)

function(add_catch2_test test_name test_src)
    get_filename_component(test_src_absolute ${test_src} REALPATH)

    add_executable(${test_name}
            ${test_src}
    )

    target_include_directories(${test_name}
            PRIVATE ${CMAKE_SOURCE_DIR}/src
    )

    target_link_libraries(${test_name}
            PRIVATE Catch2::Catch2WithMain
    )

    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()