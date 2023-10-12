cmake_minimum_required(VERSION 3.0)
project(HomeworkSubmission)
include_directories(/home/an/HomeworkSubmission/includes)
include_directories(/home/an/environment/opencv-4.4.0/include/opencv2)
include_directories(/home/an/environment/opencv-4.4.0/build/opencv2)

set(CMAKE_CXX_STANDARD 11)
set(HOME /home/an/HomeworkSubmission)

set(LIBRARY_OUTPUT_PATH ${HOME}/lib)
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)

file(GLOB SRC_LIST1 "${CMAKE_CURRENT_SOURCE_DIR}/src/static_lib_src/*.cpp")
file(GLOB SRC_LIST2 "${CMAKE_CURRENT_SOURCE_DIR}/src/shared_lib_src/*.cpp")

add_library(static_lib STATIC ${SRC_LIST1})
add_library(shared_lib SHARED ${SRC_LIST2})

link_directories(${HOME}/lib)
link_directories(/home/an/environment/opencv-4.4.0/build/lib)

link_libraries(static_lib)

add_executable(static_app ${SRC_LIST1})
add_executable(shared_app ${SRC_LIST2})

target_link_libraries(shared_app pthread shared_lib)

