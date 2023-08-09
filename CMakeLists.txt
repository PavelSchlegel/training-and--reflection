cmake_minimum_required(VERSION 3.12)
project(reflection LANGUAGES CXX)

# set(SOURCES
# read_write_file/CPP/read_write.cpp
# )

add_executable(reflection main.cpp inheritance/example_inheritance.hpp)

set_target_properties(reflection
        PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS YES
        C_STANDARD 11
        C_STANDARD_REQUIRED YES
        C_EXTENSIONS YES
)