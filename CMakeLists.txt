project (PrisDil)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)

add_executable(play play.cpp)
target_include_directories(play PUBLIC lib/include/)
target_link_libraries(play PUBLIC shakhbat_pd_lib)
