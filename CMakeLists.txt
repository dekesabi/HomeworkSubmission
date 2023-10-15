#homework 02

cmake_minimum_required(VERSION 3.0)
project(HomeworkSubmission)

set(HOME /home/Desktop/rm-01/homework-02/clone/HomeworkSubmission)
set(LIBRARY_OUTPUT_PATH ${HOME}/lib)

file(GLOB STATIC_LIB src/static_lib_src/*.cpp)
add_library(static_lib STATIC ${STATIC_LIB})

file(GLOB SHARED_LIB src/shared_lib_src/*.cpp)
add_library(shared_lib SHARED ${SHARED_LIB})

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)


add_executable(test main.cpp)
target_link_libraries(test static_lib shared_lib ${OpenCV_LIBS} ${EIGEN3_LIBS})


