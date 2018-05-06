cmake_minimum_required(VERSION 3.0)
project(Matrix)

set(CMAKE_BUILD_TYPE  Debug)
set(CMAKE_CXX_FLAGS   "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(
  matrix
  src/matrix.cpp
  src/Matrix.cpp
)

