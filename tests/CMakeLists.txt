cmake_minimum_required(VERSION 3.3)

include_directories(../)

set(SOURCE_FILES ${SOURCE_FILES} hls_unitTest_TC.cpp)
add_executable(hls_unitTest ${SOURCE_FILES})
target_link_libraries(hls_unitTest gtest gtest_main)