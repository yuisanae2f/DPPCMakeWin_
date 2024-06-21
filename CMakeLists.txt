cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

project("dppCMakeWindows")

add_subdirectory("dpp_port")
add_subdirectory("_Bin")