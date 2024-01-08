project (lib CXX)

# Include header files
include_directories(include)

# Source files
file(GLOB_RECURSE  SOURCES source/*.cpp)

# Create the static library
add_library(shakhbat_pd_lib STATIC ${SOURCES})
target_compile_options(shakhbat_pd_lib PUBLIC -std=c++20)
