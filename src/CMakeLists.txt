set(LIBGMR_SOURCES
    connection_pool.cc
)

if (LIBGMR_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(guidemyride SHARED ${LIBGMR_SOURCES})
else()
    add_library(guidemyride STATIC ${LIBGMR_SOURCES})
endif()

target_include_directories(guidemyride PUBLIC ${LIBGMR_INCLUDE_DIR})
