cmake_minimum_required(VERSION 2.8)

project(ppars-tests)

include_directories (
    ${gtest_SOURCE_DIR}/include
)

set(EXE_SOURCES
    ppars-tests.cpp
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    gtest
    gtest_main
    ${cic_LIBRARY}
)

add_test(NAME ppars_testing
         COMMAND ${PROJECT_NAME})
