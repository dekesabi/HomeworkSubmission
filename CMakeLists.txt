cmake_minimum_required(VERSION 3.15)
project(HomeworkSubmission)

set(CMAKE_CXX_STANDARD 17)

set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/includes)

set(STATIC_LIB static_lib)
set(SHARED_LIB shared_lib)
set(APP_TEST test)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/static_lib_src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/shared_lib_src)

include_directories(${HEAD_PATH})

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
link_directories(${LIB_PATH})

link_libraries(${STATIC_LIB})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
add_executable(${APP_TEST} ./main.cpp)
target_link_libraries(${APP_TEST} ${OpenCV_LIBS} Eigen3::Eigen ${SHARED_LIB})
