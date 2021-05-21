cmake_minimum_required(VERSION 3.16)
project(Making_lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(Making_lists main.cpp CustomList.cpp CustomList.h DoublyLinked.cpp DoublyLinked.h CircularList.cpp CircularList.h)