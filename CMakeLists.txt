# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(FileSystemCMake)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# # 设置输出目录
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加子目录
add_subdirectory(src/static_lib_src)
add_subdirectory(src/shared_lib_src)

# 查找OpenCV和Eigen库
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 添加可执行文件
add_executable(main main.cpp)

# 链接静态库、动态库、OpenCV和Eigen库
target_link_libraries(main PRIVATE static_lib shared_lib ${OpenCV_LIBS} Eigen3::Eigen)
