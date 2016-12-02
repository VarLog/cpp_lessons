cmake_minimum_required(VERSION 3.0)

project("lesson2" CXX)

# Compiler settings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

# Source files
file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.cpp")

# Include files directory
include_directories("include")

# Create binary execution file
set(APP_NAME "game")
add_executable(${APP_NAME} ${SOURCES} ${HEADERS})

# Set C++14 standard
set_target_properties(${APP_NAME} PROPERTIES CXX_STANDARD 14)
 
