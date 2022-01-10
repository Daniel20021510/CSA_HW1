cmake_minimum_required(VERSION 3.20)
project(CSA_HW1)

set(CMAKE_CXX_STANDARD 14)

add_executable(CSA_HW1 main.cpp objects/tree.h objects/bush.h objects/flower.h objects/tree.cpp objects/bush.cpp objects/flower.cpp objects/plant.h objects/plant.cpp container/container.h container/container.cpp "functions/additional_functions .h" functions/vowels_functions.h flags_workwer/flags_worker.h)
