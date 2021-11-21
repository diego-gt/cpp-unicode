cmake_minimum_required(VERSION 3.20)

project(cpp-unicode VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(unicode-test
	src/main.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_compile_options(unicode-test PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
	target_compile_options(unicode-test PRIVATE -Wall -Wextra -Wpedantic)
endif()