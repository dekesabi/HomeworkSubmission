cmake_minimum_required(VERSION 3.8)
add_library(static_library STATIC static_lib.cpp)
add_library(shared_library SHARED shared_lib.cpp)

target_include_directories(shared_library PUBLIC ${PROJECT_SOURCE_DIR}/includes)

target_include_directories(static_library PUBLIC ${PROJECT_SOURCE_DIR}/includes)
