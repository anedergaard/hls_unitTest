cmake_minimum_required(VERSION 3.3)
project(hls_unitTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )


# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL )

# NOTE: A change request has been submitted to the GoogleTest
#       project to remove the need for the following lines.
#       They add the gtest and gmock include directories as
#       target dependencies, since they are not added by
#       googletest (yet).
target_include_directories(gtest INTERFACE
        "${CMAKE_BINARY_DIR}/googletest-src/googletest/include" )
target_include_directories(gtest_main INTERFACE
        "${CMAKE_BINARY_DIR}/googletest-src/googletest/include" )
target_include_directories(gmock INTERFACE
        "${CMAKE_BINARY_DIR}/googletest-src/googlemock/include" )
target_include_directories(gmock_main INTERFACE
        "${CMAKE_BINARY_DIR}/googletest-src/googlemock/include" )

add_subdirectory(tests)
include_directories(.)
set(SOURCE_FILES main.cpp Runner.cpp Runner.h unitTest.cpp unitTest.h hls_unitTest.h)
add_executable(hls_unitTest_main ${SOURCE_FILES})