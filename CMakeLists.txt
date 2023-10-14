cmake_minimum_required(VERSION 3.0)
project(HW2)

# 添加 OpenCV 与 Eigen3 文件
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# 添加头文件
include_directories(${PROJECT_SOURCE_DIR}/includes
                    ${OpenCV_INCLUDE_DIRS}
                    ${Eigen3_INCLUDE_DIR}
                    )

# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# 设置路径
set(SRC_STATIC_LIB_DIR ${PROJECT_SOURCE_DIR}/src/static_lib_src)
set(SRC_SHARED_LIB_DIR ${PROJECT_SOURCE_DIR}/src/shared_lib_src)
set(LIB_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/lib)

# 创建静态库和动态库
file(GLOB SRC_STATIC_LIST ${SRC_STATIC_LIB_DIR}/*.cpp)
file(GLOB SRC_SHARED_LIST ${SRC_SHARED_LIB_DIR}/*.cpp)

set(LIBRARY_OUTPUT_PATH ${LIB_OUTPUT_DIR})

add_library(static_lib STATIC ${SRC_STATIC_LIST})
add_library(shared_lib SHARED ${SRC_SHARED_LIST})

# 生成可执行文件
add_executable(main main.cpp)

# 链接库
target_link_libraries(main static_lib shared_lib ${OpenCV_LIBS} ${EIGEN3_LIBS})