
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#ifndef GUIDEMYRIDE_SERVICES_PASSENGER_CONTROLLERS_H_
#define GUIDEMYRIDE_SERVICES_PASSENGER_CONTROLLERS_H_

#pragma once

#include <grpc++/grpc++.h>

#include <genproto/passenger.grpc.pb.h>
#include <genproto/passenger.pb.h>

using guidemyride::services::passenger::PassengerService;
using guidemyride::services::passenger::StubRequest;
using guidemyride::services::passenger::StubResponse;

using grpc::ServerContext;
using grpc::Status;

namespace guidemyride::passenger {

class PassengerServiceImpl final : public PassengerService::Service {
    Status StubMethod(ServerContext *context, const StubRequest *request,
                      StubResponse *response) override;
};

} // namespace guidemyride::passenger

#endif // GUIDEMYRIDE_SERVICES_PASSENGER_CONTROLLERS_H_
