cmake_minimum_required(VERSION 2.8)

project(lightpars)

include_directories (
)

set(LIB_SOURCE
    lightpars.cpp
    lightpars.hpp
)

add_library(${PROJECT_NAME} STATIC ${LIB_SOURCE})
