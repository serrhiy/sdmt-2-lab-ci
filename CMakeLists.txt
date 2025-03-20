cmake_minimum_required(VERSION 3.20)
project(
  sdmt-2-lab-ci
  VERSION 0.0
  DESCRIPTION "The second lab for Software development methodologies and technologies course"
  HOMEPAGE_URL https://github.com/serrhiy/sdmt-2-lab-ci
  LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_library(list INTERFACE include/List.hpp)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include" DESTINATION "${CMAKE_BINARY_DIR}")
