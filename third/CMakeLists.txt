cmake_minimum_required(VERSION 3.1)

project(third)

set(third_SRC main.cpp tokenizer.cpp Autotest.cpp)
set(third_HDR tokenizer.hpp Autotest.hpp)

#add_library(vector STATIC ${VECTOR_SRC} ${VECTOR_HDR})
add_executable(${PROJECT_NAME} ${third_SRC} ${third_HDR})