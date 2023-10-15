cmake_minimum_required(VERSION 3.0)
project(CALC)

#file
file(GLOB SRC_STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/static_lib_src/*.cpp)
file(GLOB SRC_SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/shared_lib_src/*.cpp)

#find package
find_package( OpenCV REQUIRED )
find_package (Eigen3 REQUIRED)

#add includes
include_directories(${PROJECT_SOURCE_DIR}/includes
                    ${OpenCV_INCLUDE_DIRS}
                    ${Eigen3_INCLUDE_DIR}
                    )
#set
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(static_lib STATIC ${SRC_STATIC})
add_library(shared_lib SHARED ${SRC_SHARED})

add_executable(app main.cpp)

target_link_libraries(app static_lib shared_lib ${OpenCV_LIBS} ${Eigen3_LIBS})
