
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#ifndef GUIDEMYRIDE_SERVICES_AUTH_CONTROLLERS_H_
#define GUIDEMYRIDE_SERVICES_AUTH_CONTROLLERS_H_

#pragma once

#include <grpc++/grpc++.h>

#include <genproto/auth.grpc.pb.h>
#include <genproto/auth.pb.h>

using guidemyride::services::auth::AuthService;
using guidemyride::services::auth::StubRequest;
using guidemyride::services::auth::StubResponse;

using grpc::ServerContext;
using grpc::Status;

namespace guidemyride::auth {
class AuthServiceImpl final : public AuthService::Service {
    Status StubMethod(ServerContext *context, const StubRequest *request,
                      StubResponse *response) override;
};

}; // namespace guidemyride::auth

#endif // GUIDEMYRIDE_SERVICES_AUTH_CONTROLLERS_H_
