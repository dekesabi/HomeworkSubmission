cmake_minimum_required(VERSION 3.0)
project(test)

#找opencv库并且添加头文件
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

#Eigen库只需要添加头文件
include_directories("/usr/include/eigen3")

# 定义变量
# 静态库生成的路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 测试程序生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 头文件目录
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/includes)

include_directories( ${HEAD_PATH} )

set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})

# 静态库的名字
set(STATIC_LIB static_lib)
set(SHARED_LIB shared_lib)
# 可执行程序的名字
set(APP_NAME_1 test1)

#生成动，静态库
add_subdirectory(src/shared_lib_src)
add_subdirectory(src/static_lib_src)

#包含自己的库目录
link_directories(${LIB_PATH})

#连接静态库
link_libraries(${STATIC_LIB})

#生成可执行文件
add_executable(${APP_NAME_1} main.cpp)

#连接动态库
target_link_libraries(${APP_NAME_1} ${OpenCV_LIBS} ${SHARED_LIB})




