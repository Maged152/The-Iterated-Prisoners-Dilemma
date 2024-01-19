cmake_minimum_required(VERSION 3.22)

project (IPD CXX)

add_subdirectory(lib)
add_subdirectory(test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(play play.cpp)
target_link_libraries(play PUBLIC shakhbat_pd_lib)
target_include_directories(play PUBLIC include)