cmake_minimum_required(VERSION 3.16)

project(FirstTouchSchool)

set(CMAKE_CXX_STANDARD 17)

# Enable Qt automatic tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# IMPORTANT: Enable RC compiler (for .ico in exe)
enable_language(RC)


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
    src/database/StudentTableInitializer.cpp
    src/database/TeacherTableInitializer.cpp
    src/database/FeesTableInitializer.cpp
    src/database/ClassTableInitializer.cpp

    # repositories
    src/repositories/UserRepository.cpp
    src/repositories/StudentRepository.cpp
    src/repositories/TeacherRepository.cpp
    src/repositories/ClassRepository.cpp

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

    # widgets/students
    src/widgets/students/StudentsWidget.cpp

    #widgets/teachers
    src/widgets/teachers/TeachersWidget.cpp

    # widget/fees
    src/widgets/fees/FeesWidget.cpp

    # widget/class
    src/widgets/class/ClassWidget.cpp
    src/widgets/class/ClassCardWidget.cpp
    src/widgets/class/ClassDetailsWidget.cpp
    src/widgets/class/ClassStudentTableWidget.cpp
    src/widgets/class/ClassActionBarWidget.cpp
    


  
    
)

# Header files
set(HEADERS
    src/database/DatabaseManager.h
    src/database/StudentTableInitializer.h
    src/database/DatabaseInitializer.h
    src/database/ClassTableInitializer.h
    src/database/FeesTableInitializer.h

    src/windows/WelcomeWindow.h
    src/windows/SetupWindow.h
    src/windows/LoginWindow.h

    src/repositories/UserRepository.h
    src/repositories/StudentRepository.h
    src/repositories/TeacherRepository.h
    src/repositories/ClassRepository.h
    src/repositories/FeesRepository.h

    src/utils/PasswordUtils.h
    src/windows/DashboardWindow.h
    src/windows/SystemDashboard.h
    src/widgets/dashboard/HeaderWidget.h
    src/widgets/dashboard/SidebarWidget.h
    src/widgets/dashboard/MainSectionWidget.h
    src/widgets/students/StudentsWidget.h
    src/widgets/teachers/TeachersWidget.h

    # widgets/classes
    src/widgets/class/ClassWidget.h
    src/widgets/class/ClassCardWidget.h
    src/widgets/class/ClassDetailsWidget.h
    src/widgets/class/ClassStudentTableWidget.h
    src/widgets/class/ClassActionBarWidget.h


    #widget/fees
)


#====================================================
# WINDOWS EXE ICON 
#====================================================

set(APP_ICON_RESOURCE_WINDOWS 
   ${CMAKE_SOURCE_DIR}/assets/app_icon.rc
  )

# Create executable
add_executable(FirstTouchSchool
    ${SOURCES}
    ${HEADERS}
    ${APP_ICON_RESOURCE_WINDOWS}
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