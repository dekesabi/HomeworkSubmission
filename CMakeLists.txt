cmake_minimum_required(VERSION 3.0)
project(homework2)

find_package(OpenCV REQUIRED)
#指定头文件所在目录
include_directories(${PROJECT_SOURCE_DIR}/includes ${OpenCV_INCLUDE_DIRS})
#指定静态库与动态库的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#制作静态库
add_library(staticlib STATIC ./src/static_lib_src/static_lib.cpp)
#制作动态库
add_library(sharedlib SHARED ./src/shared_lib_src/shared_lib.cpp)
# 包含静态库路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
# 链接静态库
link_libraries(staticlib)
# 指定要链接的动态库的路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(app main.cpp)
# 指定可执行程序要链接的动态库名字
target_link_libraries(app sharedlib ${OpenCV_LIBS})
