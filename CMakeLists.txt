project (PrisDil CXX)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
set(CMAKE_CXX_COMPILER g++ CACHE STRING "" FORCE)
set(CMAKE_C_COMPILER gcc CACHE INTERNAL "" FORCE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(play play.cpp)
target_include_directories(play PUBLIC lib/include/)
target_link_libraries(play PUBLIC shakhbat_pd_lib)
target_compile_options(play PUBLIC -std=c++20)