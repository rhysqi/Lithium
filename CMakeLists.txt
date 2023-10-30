cmake_minimum_required(VERSION 3.26)
project(Lithium)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED true)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -L/usr/local/lib")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11")

set(SOURCES
    src/lithium.cc

    src/temp/core.cc
    src/temp/temp.cc
    src/temp/handling.cc

    src/component/window.cc
    src/component/canvas.cc
    src/component/button.cc
    src/component/menu.cc
    src/component/menubar.cc

    src/plugins/lsp.cc
)

add_executable(program ${SOURCES})
