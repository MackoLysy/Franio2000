cmake_minimum_required(VERSION 3.5)

project(Franio2000)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(thirdparty)
file(GLOB SOURCES
    "*.cpp"
    "thirdparty/utils/*.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})