cmake_minimum_required(VERSION 3.20)
project(bcf)

set(CMAKE_CXX_STANDARD 14)

include_directories(dirstats)

add_executable(bcf
        dirstats/dirstats-cli.cpp
        dirstats/dirstats-cli.h)
