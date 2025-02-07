
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

cmake_minimum_required(VERSION 3.25.1)

project(guidemyride
        DESCRIPTION "Guide My Ride"
        VERSION 0.1.0
        LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CheckCompiler)
include(CTest)

# build options
option(GMR_BUILD_AUTH      "Build authentication service" ON)
option(GMR_BUILD_DRIVER    "Build driver service"         ON)
option(GMR_BUILD_PASSENGER "Build passenger service"      ON)

option(GMR_BUILD_COMMON "Build common library" ON)
option(GMR_BUILD_PROTOS "Build proto files"    ON)

# global c++ options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# subdirectories
add_subdirectory(libs)      # libraries
add_subdirectory(proto)     # protobuf files
add_subdirectory(services)  # services
