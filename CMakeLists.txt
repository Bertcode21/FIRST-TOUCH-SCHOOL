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

    # database
    src/database/DatabaseManager.cpp
    src/database/DatabaseInitializer.cpp

    # repositories
    src/repositories/UserRepository.cpp

    # utils
    src/utils/PasswordUtils.cpp

    # windows
    src/windows/WelcomeWindow.cpp
    src/windows/SetupWindow.cpp
    src/windows/LoginWindow.cpp
    src/windows/DashboardWindow.cpp
    src/windows/SystemDashboard.cpp

    #widgets/dashbaord reusable
    src/widgets/dashboard/HeaderWidget.cpp
    src/widgets/dashboard/SidebarWidget.cpp
    src/widgets/dashboard/MainSectionWidget.cpp
)

# Header files
set(HEADERS
    src/database/DatabaseManager.h
    src/windows/WelcomeWindow.h
    src/windows/SetupWindow.h
    src/windows/LoginWindow.h
    src/database/DatabaseInitializer.h
    src/repositories/UserRepository.h
    src/utils/PasswordUtils.h
    src/windows/DashboardWindow.h
    src/windows/SystemDashboard.h
    src/widgets/dashboard/HeaderWidget.h
    src/widgets/dashboard/SidebarWidget.h
    src/widgets/dashboard/MainSectionWidget.h
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

# # Force output directory so you ALWAYS know where exe is
# set_target_properties(FirstTouchSchool PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
# )

# Force output directory so EXE is ALWAYS in build/
set_target_properties(FirstTouchSchool PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)