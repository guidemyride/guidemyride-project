
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(Protobuf REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(GMR_PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/genproto")
set(GMR_PROTO_IMPORT_DIR "${CMAKE_CURRENT_LIST_DIR}")

file(MAKE_DIRECTORY ${GMR_PROTO_BINARY_DIR})

set(GMR_PROTO_SOURCES
    "${GMR_PROTO_IMPORT_DIR}/auth.proto"
)

add_library(gmr-protos OBJECT ${GMR_PROTO_SOURCES})
add_library(guidemyride::protos ALIAS gmr-protos)

target_link_libraries(gmr-protos
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc++
)

target_include_directories(gmr-protos
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# generate protocol buffers files
protobuf_generate(
    TARGET
        gmr-protos
    IMPORT_DIRS
        "${GMR_PROTO_IMPORT_DIR}"
    PROTOC_OUT_DIR
        "${GMR_PROTO_BINARY_DIR}"
)

# generate gRPC files
protobuf_generate(
    TARGET
        gmr-protos LANGUAGE grpc
    GENERATE_EXTENSIONS
        .grpc.pb.h .grpc.pb.cc
    PLUGIN
        "protoc-gen-grpc=\$<TARGET_FILE:gRPC::grpc_cpp_plugin>"
    IMPORT_DIRS
        "${GMR_PROTO_IMPORT_DIR}"
    PROTOC_OUT_DIR
        "${GMR_PROTO_BINARY_DIR}"
)

