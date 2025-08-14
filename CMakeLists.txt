cmake_minimum_required(VERSION 3.10)
project(tbengine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(tbengine_terminal STATIC
    src/tbmeta.c
    src/terminal/tbextra.c
    src/terminal/tblib.c
)
target_include_directories(tbengine_terminal
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
#[===[
find_package(SDL3 QUIET)
if (SDL3_FOUND)
    find_package(SDL3_ttf QUIET)
    if (SDL3_ttf_FOUND)
        target_include_directories(tbengine_sdl
            PUBLIC
            ${PROJECT_SOURCE_DIR}/include
        )
        add_library(tbengine_sdl STATIC
            src/tbmeta.c
            src/sdl/tbsdl.cpp
        )
        target_link_libraries(tbengine_sdl PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
    endif()
endif()
]===]
add_executable(tbtest
    demo/main.c
)
target_link_libraries(tbengine_terminal PRIVATE)
target_link_libraries( tbtest
    PRIVATE
        tbengine_terminal
)
