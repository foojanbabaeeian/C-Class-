cmake_minimum_required(VERSION 3.21)
project(RestaurantMenu)

set(CMAKE_CXX_STANDARD 14)

add_executable(RestaurantMenu main.cpp food.cpp food.h person.cpp person.h)
