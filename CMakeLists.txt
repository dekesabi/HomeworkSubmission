cmake_minimum_required(VERSION 3.8)
project(homework2)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(OpenCV_DIR /path/to/opencv)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_subdirectory(src)


add_executable(test main.cpp)


target_link_libraries(test shared_library)
target_link_libraries(test static_library)
target_link_libraries(test ${OpenCV_LIBS})


target_include_directories(test PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include
${PROJECT_SOURCE_DIR}/../../environment ${PROJECT_SOURCE_DIR}/src/shared_lib_src ${PROJECT_SOURCE_DIR}/src/static_lib_src)
