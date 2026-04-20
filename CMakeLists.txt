cmake_minimum_required(VERSION 3.10)
project(RTinOneWeekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ONE_WEEKEND_SRC
src/main.cc)

include_directories(src)

add_executable(main ${ONE_WEEKEND_SRC})
