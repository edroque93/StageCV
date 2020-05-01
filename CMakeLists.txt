cmake_minimum_required(VERSION 3.5)

project(StageCV VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_VERBOSE_MAKEFILE True)
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable")
endif()

set(SOURCE src/main.cpp src/ScaleStage.cpp src/VideoCaptureStage.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

find_package(OpenCV REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
