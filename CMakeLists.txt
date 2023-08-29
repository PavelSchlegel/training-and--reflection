cmake_minimum_required(VERSION 3.12)
project(reflection LANGUAGES CXX)

set(SOURCES
        Qsort_Pool/threadpool.cpp
        Qsort_Pool/threadpool.hpp
        Qsort_Pool/headers.hpp
        Qsort_Pool/blockedqueue.hpp
)

add_executable(reflection main.cpp ${SOURCES})

set_target_properties(reflection
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS YES
        C_STANDARD 11
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS YES
)