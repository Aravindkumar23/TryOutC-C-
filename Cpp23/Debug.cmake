# cmake/DebugSetup.cmake
# --------------------------------------
# This script configures CMake and your compiler for a full debug setup
# Run directly or include() from your main CMakeLists.txt
# --------------------------------------
cmake_minimum_required(VERSION 3.13)
project(Cpp23 LANGUAGES CXX)
# Print a header for clarity
message(STATUS "🧩 Debug.cmake — Configuring Debug Environment")

# ✅ Ensure Debug build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()

# ✅ Enable verbose build (show compiler/linker commands)
set(CMAKE_VERBOSE_MAKEFILE ON)

# ✅ Compiler settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ Custom debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# ✅ Detect compiler and append sanitizer/debug options if supported
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi /Od")
endif()

# ✅ Add an app-level debug macro
add_compile_definitions(APP_DEBUG)

# ✅ Print summary
message(STATUS "------------------------------------------")
message(STATUS "🔧 Build type          : ${CMAKE_BUILD_TYPE}")
message(STATUS "🔧 Compiler ID         : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "🔧 Compiler path       : ${CMAKE_CXX_COMPILER}")
message(STATUS "🔧 Debug Flags         : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "🔧 Verbose Makefile    : ${CMAKE_VERBOSE_MAKEFILE}")
message(STATUS "🔧 APP_DEBUG defined   : ON")
message(STATUS "------------------------------------------")
# End of DebugSetup.cmake