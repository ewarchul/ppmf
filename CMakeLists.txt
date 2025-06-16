cmake_minimum_required(VERSION 3.25)

project(ppmf 
  LANGUAGES CXX
  VERSION 0.0.1
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(third-party/libcmaes)
add_subdirectory(src)


