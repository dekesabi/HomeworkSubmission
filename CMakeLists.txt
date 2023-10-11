cmake_minimum_required(VERSION 3.0.0)
project(work2)
set(CMAKE_CXX_STANDARD 17)
set(CURRENT_PATH /home/jayyxl/homework2/HomeworkSubmission)

include_directories(${CURRENT_PATH}/includes)
#include_directories(./src/static_lib_src/static_lib.cpp)
file(GLOB SRC_STATIC ${CURRENT_PATH}/src/static_lib_src/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CURRENT_PATH}/lib)
add_library(staticwork STATIC ${SRC_STATIC})

include_directories((${CURRENT_PATH}/includes))
#include_directories(./src/shared_lib_src/shared_lib.cpp)
file(GLOB SRC_SHARED ${CURRENT_PATH}/src/shared_lib_src/*.cpp)
set(LIBRARY_OUTPUT_PATH ${CURRENT_PATH}/lib)  
add_library(sharedwork SHARED ${SRC_SHARED})

#please pay attention to the path,you'd better make it absolute
include_directories((${CURRENT_PATH}/includes))
link_directories(${CURRENT_PATH}/lib)
link_libraries(staticwork)

#seek for opencv and Eigen
#it seems that Eigen3 is a header code base,so whether to link it or not?
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Eigen3 REQUIRED)
include_directories(${Eigen3_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${CURRENT_PATH}/bin)  #output place
add_executable(app main.cpp)

#link the dynamic store after execute
target_link_libraries(app sharedwork ${OpenCV_LIBS})


