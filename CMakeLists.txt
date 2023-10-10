cmake_minimum_required(VERSION 3.0)

project(hw2) 

# Find OpenCV package
find_package(OpenCV REQUIRED)
# Check if OpenCV was found
if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV package not found")
endif()
include_directories(${OpenCV_INCLUDE_DIRS})

# Find Eigen package
find_package(Eigen3 REQUIRED)
# Check if Eigen was found
if(NOT Eigen3_FOUND)
    message(FATAL_ERROR "Eigen library not found")
endif()
include_directories(${Eigen3_INCLUDE_DIRS})

# static lib
add_subdirectory(src/static_lib_src)

# shared lib
add_subdirectory(src/shared_lib_src)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
add_executable(${project} main.cpp)
target_link_libraries(${project} PUBLIC ${OpenCV_LIBS} Eigen3::Eigen static_lib shared_lib)