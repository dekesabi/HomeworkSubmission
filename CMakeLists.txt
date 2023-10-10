cmake_minimum_required(VERSION 3.0)

project(hw2)

# set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Find OpenCV package
find_package(OpenCV REQUIRED)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV package not found")
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

# Find Eigen package
find_package(Eigen3 REQUIRED)

if(NOT Eigen3_FOUND)
    message(FATAL_ERROR "Eigen library not found")
endif()

include_directories(${Eigen3_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# static lib
add_subdirectory(src/static_lib_src)

# shared lib
add_subdirectory(src/shared_lib_src)

add_executable(main main.cpp)

target_link_libraries(main ${OpenCV_LIBS} Eigen3::Eigen static_lib shared_lib)