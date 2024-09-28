set(LIBGMR_SOURCES
    connection_pool.cc
)

add_library(guidemyride STATIC ${LIBGMR_SOURCES})
target_include_directories(guidemyride PUBLIC ${LIBGMR_INCLUDE_DIR})
