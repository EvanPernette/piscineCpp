cmake_minimum_required(VERSION 3.21.2)

project(cipeek)

add_executable(cipeek src/cipeek.cc)

target_include_directories(cipeek PUBLIC include/)

target_link_libraries(cipeek PRIVATE ciutils)

set_target_properties(cipeek PROPERTIES CXX_STANDARD 20 
CXX_EXTENSIONS OFF)

target_compile_options(cipeek PRIVATE -Wall -Wextra -Werror -pedantic)
