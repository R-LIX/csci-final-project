cmake_minimum_required(VERSION 3.16)
project(csci_final_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")
endif()

# Console version (unchanged)
add_executable(oscar oscar.cpp)

# Clickable Qt version
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
add_executable(oscar_gui oscar_gui.cpp)
target_link_libraries(oscar_gui PRIVATE Qt6::Widgets)
