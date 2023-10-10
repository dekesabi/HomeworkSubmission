cmake_minimum_required(VERSION 3.12)
project(homework)

# 设置输出文件夹
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# 构建静态库
add_library(hw_static STATIC 
    src/shared_lib_src/shared_lib.cpp
)
target_include_directories(hw_static
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/includes
)

# 构建动态库
add_library(hw_shared SHARED 
    src/static_lib_src/static_lib.cpp
)
target_include_directories(hw_shared
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/includes
)

# 寻找外部库
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}) 
include_directories(${EIGEN3_INCLUDE_DIRS})

# 构建执行文件
add_executable(hw_main main.cpp)
target_link_libraries(hw_main PRIVATE hw_static hw_shared ${OpenCV_LIBS} Eigen3::Eigen)


