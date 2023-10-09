cmake_minimum_required(VERSION 3.0)
project(textlib)
set(Open_CV_DIR /helloworld/opencv/opencv-4.4.0)
set(Eigen3_DIR /helloworld/eigen-3.4.0)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(/${CMAKE_CURRENT_SOURCE_DIR}/includes ${OpenCV_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR})
link_directories(/${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(app ${OpenCV_LIBS} ${Eigen3_LIBS} zuoye1 zuoye2)


