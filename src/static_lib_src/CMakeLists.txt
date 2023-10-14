
# 添加静态库源文件
add_library(static_lib STATIC static_lib.cpp)

# 设置库的输出路径
set_target_properties(static_lib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

target_include_directories(static_lib PUBLIC ${CMAKE_SOURCE_DIR}/includes)
