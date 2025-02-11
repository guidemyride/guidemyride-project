
// SPDX-License-Identifier: MIT
// Copyright (c) 2024-2025 nyashbox

#include "controllers.h"

namespace guidemyride::driver {

Status DriverServiceImpl::StubMethod(ServerContext *context,
                                     const StubRequest *request,
                                     StubResponse *response) {
    return Status::OK;
};

}; // namespace guidemyride::driver
