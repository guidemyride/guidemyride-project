
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#ifndef GUIDEMYRIDE_SERVICES_DRIVER_CONTROLLERS_H_
#define GUIDEMYRIDE_SERVICES_DRIVER_CONTROLLERS_H_

#pragma once

#include <grpc++/grpc++.h>

#include <genproto/driver.grpc.pb.h>
#include <genproto/driver.pb.h>

using guidemyride::services::driver::DriverService;
using guidemyride::services::driver::StubRequest;
using guidemyride::services::driver::StubResponse;

using grpc::ServerContext;
using grpc::Status;

namespace guidemyride::driver {

class DriverServiceImpl final : public DriverService::Service {
    Status StubMethod(ServerContext *context, const StubRequest *request,
                      StubResponse *response) override;
};

} // namespace guidemyride::driver

#endif // GUIDEMYRIDE_SERVICES_DRIVER_CONTROLLERS_H_
