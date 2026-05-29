cmake_minimum_required(VERSION 3.16)

project(FirstTouchSchool)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt automatic tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt modules
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

# Include directories
include_directories(
    src
    src/database
)

# Source files
set(SOURCES
    src/main.cpp
    src/database/DatabaseManager.cpp
    src/windows/WelcomeWindow.cpp
)

# Header files
set(HEADERS
    src/database/DatabaseManager.h
    src/windows/WelcomeWindow.h
)

# Create executable
add_executable(FirstTouchSchool
    ${SOURCES}
    ${HEADERS}
)

# Link Qt libraries
target_link_libraries(FirstTouchSchool PRIVATE
    Qt6::Widgets
    Qt6::Sql
)