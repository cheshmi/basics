# Created by SwiftWare Lab on 9/24.
# CE 4SP4 - High Performance Programming
# Copyright (c) 2024 SwiftWare Lab

cmake_minimum_required(VERSION 3.18)

option(PROFILING_ENABLED "Enables Modules for Profiling, needs LIBFPM4" OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
include(FetchContent)

FetchContent_Declare(
        argparse
        GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

## LIBPFM4
#include(ExternalProject)
#ExternalProject_Add( libpfm4
#        GIT_REPOSITORY https://github.com/wcohen/libpfm4.git
#        CONFIGURE_COMMAND ./configure
#        BUILD_COMMAND make
#        INSTALL_COMMAND make PREFIX=${CMAKE_BINARY_DIR}/libpfm4 install
#        BUILD_IN_SOURCE 1
#        BUILD_BYPRODUCTS ${CMAKE_BINARY_DIR}/libpfm4/lib/libpfm.so
#        )



include(FetchContent)
FetchContent_Declare(
        googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.9.0
)
# enable BENCHMARK_DOWNLOAD_DEPENDENCIES
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
if (PROFILING_ENABLED)
  # enable PFM
  set(BENCHMARK_ENABLE_LIBPFM ON)
endif()



FetchContent_MakeAvailable(googlebenchmark)




include_directories(
        ${CMAKE_SOURCE_DIR}/include)

project(basics)

set(CMAKE_CXX_STANDARD 17)

add_executable(basics
        ${CMAKE_SOURCE_DIR}/vec_add_driver.cpp
        ${CMAKE_SOURCE_DIR}/src/vec_add.cpp
        )
target_link_libraries(basics
        benchmark::benchmark )