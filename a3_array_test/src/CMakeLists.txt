cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 检查编译器是否支持 C++20

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++20" COMPILER_SUPPORTS_CXX20)

# if(COMPILER_SUPPORTS_CXX20)
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
# else()
#     message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} does not support C++20.")
# endif()


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

aux_source_directory(. SRC_LIST)
include_directories(../include)


add_executable(main main.cpp ${SRC_LIST})