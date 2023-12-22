cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


aux_source_directory(. SRC_LIST)
include_directories(../include)


add_executable(main main.cpp ${SRC_LIST})