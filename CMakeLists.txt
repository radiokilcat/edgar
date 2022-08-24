cmake_minimum_required(VERSION 3.17)
project(edgar)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(Boost_USE_MULTITHREADED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(edgar main.cpp telegram_interface.cpp telegram_interface.hpp settings.cpp settings.hpp)

target_link_libraries(edgar ${CONAN_LIBS})
