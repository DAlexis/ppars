cmake_minimum_required(VERSION 2.8)

project(lightpars-tests)

include_directories (
    ${gtest_SOURCE_DIR}/include
    ${lightpars_SOURCE_DIR}
)

set(EXE_SOURCES
    lightpars-tests.cpp
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    gtest
    gtest_main
    lightpars
)

add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})
