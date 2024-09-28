set(LIBGMR_SOURCES
    connection_pool.cc
)

add_library(libguidemyride STATIC ${LIBGMR_SOURCES})
target_include_directories(libguidemyride PUBLIC ${LIBGMR_INCLUDE_DIR})
