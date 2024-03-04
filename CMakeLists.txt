cmake_minimum_required(VERSION 3.20.2)

project(example)

enable_testing()

add_executable(${PROJECT_NAME} example.c)
target_include_directories(${PROJECT_NAME} PRIVATE .)

add_test(NAME ${PROJECT_NAME} COMMAND ./example)
