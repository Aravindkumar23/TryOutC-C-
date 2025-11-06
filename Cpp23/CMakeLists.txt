cmake_minimum_required(VERSION 3.20)
project(Cpp23 LANGUAGES CXX)

# Use C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the executable
add_executable(cpp23 src/main.cpp src/helper.cpp) # defines name here

# Add extra compile flags (like -pedantic) cleanly
target_compile_options(cpp23 PRIVATE -pedantic)