cmake_minimum_required(VERSION 3.12)
project(reflection LANGUAGES CXX)

include(FetchContent)
enable_testing()

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(mylib)

# set(SOURCES
        # Qsort_Pool/threadpool.cpp
        # Qsort_Pool/threadpool.hpp
        # Qsort_Pool/headers.hpp
        # Qsort_Pool/blockedqueue.hpp
# )

add_executable(reflection main.cpp)
target_link_libraries(reflection PUBLIC mylib)

set_target_properties(reflection
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS YES
        C_STANDARD 11
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS YES
)