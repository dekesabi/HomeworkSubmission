cmake_minimum_required(VERSION 3.10)

project(HomeworkSubmission VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

file(GLOB_RECURSE SHARE_LIB src/shared_lib_src/*.cpp)
ADD_LIBRARY(shared_lib SHARED ${SHARE_LIB})

file(GLOB_RECURSE STATIC_LIB src/static_lib_src/*.cpp)
add_library(static_lib STATIC ${STATIC_LIB})

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

# set(CMAKE_BUILD_TYPE Debug)
include_directories(
  includes
  ${OpenCV_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_executable(demo main.cpp)
target_link_libraries(demo static_lib shared_lib ${OpenCV_LIBS} ${EIGEN3_LIBS})
