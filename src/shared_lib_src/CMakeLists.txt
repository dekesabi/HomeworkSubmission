cmake_minimum_required(VERSION 3.0)
project(shared_lib)
aux_source_directory(./ SRC)
include_directories(${HEAD_PATH})
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
add_library(${SHARED_LIB} SHARED ${SRC})

