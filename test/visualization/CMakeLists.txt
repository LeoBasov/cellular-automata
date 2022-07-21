cmake_minimum_required(VERSION 3.10)

project(ca_visualization_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "--coverage")

find_package(GTest REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(OpenMP REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})
file(GLOB_RECURSE sources ../../src/*.cc *.cc ../../src/*.h *.h)
list(FILTER sources EXCLUDE REGEX "../src/main.cc")
add_executable(visualization_tests ${sources})
target_link_libraries(visualization_tests ${GTEST_LIBRARIES} ${EIGEN3_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} OpenMP::OpenMP_CXX)
