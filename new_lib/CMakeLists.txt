# cmake_minimum_required(VERSION 3.12)
project(new_lib)

add_library(${PROJECT_NAME} STATIC new_lib.cpp)
# set_target_properties(${PROJECT_NAME}
#     PROPERTIES
#         CXX_STANDARD 17
#         CXX_STANDARD_REQUIRED YES
#         CXX_EXTENSIONS YES
#         C_STANDARD 11
#         C_STANDARD_REQUIRED YES
#         C_EXTENSIONS YES
# )

target_link_libraries(${PROJECT_NAME} PUBLIC Boost::json)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})