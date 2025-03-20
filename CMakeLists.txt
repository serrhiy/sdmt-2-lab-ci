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
option(STATIC_LIBRARY "Build static library" OFF)
if(STATIC_LIBRARY)
  add_library(list STATIC src/List.cpp include/List.hpp)  
  set_target_properties(list PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
  target_include_directories(list PUBLIC "${PROJECT_SOURCE_DIR}/include")
else()
  add_library(list SHARED src/List.cpp include/List.hpp)
  set_target_properties(list PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
  target_include_directories(list PUBLIC "${PROJECT_SOURCE_DIR}/include")
endif()
