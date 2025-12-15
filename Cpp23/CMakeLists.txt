cmake_minimum_required(VERSION 3.20)
project(Cpp23 LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/Debug.cmake)
include_directories(cpp23 PRIVATE ${CMAKE_SOURCE_DIR}/src/ClassStruct)

# 🔹 Collect all .cpp files recursively inside src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# 🔹 Optional: print them for confirmation
message(STATUS "Source files: ${SRC_FILES}")

#define the executable using the collected source files
add_executable(cpp23 ${SRC_FILES})

# Define the executable
# add_executable(cpp23 src/main.cpp src/helper.cpp src/Day1/day1.cpp src/Day1/day1practice.cpp src/Day2/day2.cpp)  # defines name here

# Add extra compile flags (like -pedantic) cleanly
target_compile_options(cpp23 PRIVATE -pedantic)