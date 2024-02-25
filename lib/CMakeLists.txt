cmake_minimum_required(VERSION 3.22)
project (shakhbat_pd CXX)

# Source files
file(GLOB_RECURSE SOURCES source/*.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create the static library
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)


install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/package)
install(DIRECTORY include DESTINATION ${CMAKE_SOURCE_DIR}/package)
