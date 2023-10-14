cmake_minimum_required(VERSION 3.12)
project(FileSystemCMake)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src/static_lib_src)
add_subdirectory(src/shared_lib_src)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE static_lib shared_lib ${OpenCV_LIBS} Eigen3::Eigen)
