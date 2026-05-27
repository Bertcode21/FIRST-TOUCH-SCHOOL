cmake_minimum_required(VERSION 3.16)

project(FirstTouchSchool)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(FirstTouchSchool src/main.cpp)

target_link_libraries(FirstTouchSchool PRIVATE Qt6::Widgets)