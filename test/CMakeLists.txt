cmake_minimum_required(VERSION 3.5)

project (google_test_example)

add_subdirectory(GTest)

enable_testing()

include_directories(../lib/inc/)

include_directories(../lib/thirdparty)
include_directories(../lib/thirdparty/utils/)

file(GLOB SOURCES
    "../lib/src/*.cpp"
    "../lib/thirdparty/utils/*.cpp"
    "*.cpp"
)
add_executable(tests ${SOURCES})

target_link_libraries(
    tests
    GTest::GTest 
    GTest::Main
)

add_test(test_all tests)
