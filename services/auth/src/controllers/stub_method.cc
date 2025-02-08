
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#include "controllers.h"

namespace guidemyride::auth {
Status AuthServiceImpl::StubMethod(ServerContext *context,
                                   const StubRequest *request,
                                   StubResponse *response) {
    return grpc::Status::OK;
};

}; // namespace guidemyride::auth
