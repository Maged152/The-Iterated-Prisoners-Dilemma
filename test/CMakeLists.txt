cmake_minimum_required(VERSION 3.22)
project (test CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target for the test
add_executable(pd_test shakhbat_pd_test.cpp)

# Link the library to the test executable
target_link_libraries(pd_test PUBLIC shakhbat_pd)

add_custom_target(run_test
    COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/Axelrod.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "\nRunning Python script"
    COMMAND ${CMAKE_COMMAND} -E echo "Running pd_test"
    COMMAND  $<TARGET_FILE:pd_test>
)