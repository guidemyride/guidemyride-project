
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#include "controllers/controllers.h"

#include <string>

using guidemyride::passenger::PassengerServiceImpl;

int main(int argc, char *argv[]) {
    std::string serverAddress("0.0.0.0:50051");
    grpc::ServerBuilder builder;
    PassengerServiceImpl service;

    builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server{builder.BuildAndStart()};
    server->Wait();

    return 0;
}
