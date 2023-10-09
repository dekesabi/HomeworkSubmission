cmake_minimum_required(VERSION 3.12)

project(my_project)

# 添加你的静态库和动态库子目录
add_subdirectory(src/static_lib)
add_subdirectory(src/shared_lib)

# 设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# 添加OpenCV和Eigen的依赖
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 添加可执行文件
add_executable(my_program src/main.cpp)

# 链接静态库、动态库、OpenCV和Eigen
target_link_libraries(shared SHARED ${PROJECT_SOURCE_DIR}/includes/shared_lib.hpp)
target_link_libraries(static SHARED ${PROJECT_SOURCE_DIR}/includes/static_lib.hpp)

target_link_libraries(my_program PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)

# 添加包含目录
target_include_directories(my_program PRIVATE ${CMAKE_SOURCE_DIR}/include)
