project(mylib LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC mylib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}-test test.cpp)
target_link_libraries(${PROJECT_NAME}-test PUBLIC ${PROJECT_NAME} gtest_main gmock gtest)
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-test)
