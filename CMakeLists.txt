cmake_minimum_required(VERSION 3.2)
project(Lithium)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED true)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include -L/usr/local/lib")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing -fstack-protector-strong")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -flto")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lX11")

set(SOURCES
    src/lithium.cc

    src/lib/Lt-Core.cc
    src/lib/Lt-Component.cc
    src/lib/Lt-Parser.cc
)

add_executable(Lithium ${SOURCES})
