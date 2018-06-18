cmake_minimum_required(VERSION 3.9)
project(SEU_vending_machine)

set(CMAKE_CXX_STANDARD 11)

add_executable(SEU_vending_machine main.cpp vendor.cpp VIP.cpp MANU.cpp)
