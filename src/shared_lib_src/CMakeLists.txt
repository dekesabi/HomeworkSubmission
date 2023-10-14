
# 添加动态库源文件
add_library(shared_lib SHARED shared_lib.cpp)

# 设置库的输出路径
set_target_properties(shared_lib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(shared_lib PUBLIC ${CMAKE_SOURCE_DIR}/includes)
