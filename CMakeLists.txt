cmake_minimum_required(VERSION 3.17)
project(PA3_Data_Compression)

set(CMAKE_CXX_STANDARD 11)

add_executable(PA3_Data_Compression source/main.cpp source/headers/encoder.h source/headers/decoder.h source/headers/sapling_node.h source/classes/tree_builder.cpp)