cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# 添加静态库源文件
add_library(static_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/static_lib_src/static_lib.cpp)

# 添加动态库源文件
add_library(shared_lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/shared_lib_src/shared_lib.cpp)

# 添加opencv库
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加Eigen库
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

# 添加可执行文件
add_executable(MyExecutable ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# 链接静态库、动态库和其他库
target_link_libraries(MyExecutable static_lib shared_lib ${OpenCV_LIBS} ${EIGEN3_LIBRARIES})

