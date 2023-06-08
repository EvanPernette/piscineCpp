cmake_minimum_required(VERSION 3.21.2)

project(ciultils)

find_library(YAML yaml-cpp REQUIRED)

add_library(ciutils SHARED src/ciutils.cc)

target_include_directories(ciutils PUBLIC include/)

target_link_libraries(ciutils PRIVATE ${YAML})

set_target_properties(ciutils  PROPERTIES CXX_STANDARD 20 
CXX_EXTENSIONS OFF)

target_compile_options(ciutils PRIVATE -Wall -Wextra -Werror -pedantic)

add_subdirectory(cipeek)