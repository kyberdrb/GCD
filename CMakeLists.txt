cmake_minimum_required(VERSION 3.13)
project(GCD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(GOOGLE_TEST_DIR "testing/googleTest")
add_subdirectory(${GOOGLE_TEST_DIR})
include_directories(${GOOGLE_TEST_DIR}/googletest/include)

set(GCD_FINDER_PATH gcdFinder)
set(GCD_NUMBER_PATH gcdNumber)
set(GCD_PAIR_PATH gcdPair)
set(INDEX_PAIR_PATH indexPair)
set(TESTS_PATH testing/tests)
set(TEST_RUNNER_PATH testing/testRunner)
set(UTILS_PATH utils)

file(GLOB_RECURSE SOURCE_FILES_CPP
        "gcd.cpp"
        "${GCD_FINDER_PATH}/*.cpp"
        "${GCD_NUMBER_PATH}/*.cpp"
        "${GCD_PAIR_PATH}/*.cpp"
        "${INDEX_PAIR_PATH}/*.cpp"
        "${TESTS_PATH}/*.cpp"
        "${TEST_RUNNER_PATH}/*.cpp"
        "${UTILS_PATH}/*.cpp"
)

file(GLOB_RECURSE SOURCE_FILES_HEADERS
        "${GCD_FINDER_PATH}/*.h"
        "${GCD_NUMBER_PATH}/*.h"
        "${GCD_PAIR_PATH}/*.h"
        "${INDEX_PAIR_PATH}/*.h"
        "${TEST_RUNNER_PATH}/*.h"
        "${UTILS_PATH}/*.h"
)

set(SOURCE_FILES
        ${SOURCE_FILES_CPP}
        ${SOURCE_FILES_HEADERS}
)
add_executable(GCD ${SOURCE_FILES})

target_link_libraries(GCD gtest gtest_main)