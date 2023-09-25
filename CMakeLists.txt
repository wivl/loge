cmake_minimum_required(VERSION 3.12)
project(loge VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

add_library(loge OBJECT)
target_sources(loge PRIVATE src/loge.cpp include/loge/loge.hpp)
target_include_directories(loge PUBLIC include)




