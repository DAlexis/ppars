cmake_minimum_required(VERSION 2.8)

project(example1)

include_directories (
)

set(EXE_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${EXE_SOURCES})

target_link_libraries (${PROJECT_NAME}
    
)
