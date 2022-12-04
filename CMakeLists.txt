cmake_minimum_required(VERSION 3.24)
project(Trivia)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trivia main.cpp "Data Structures and Algorithms/Map.h" Trivia.h "Data Structures and Algorithms/UnsortedPQ.h" "Data Structures and Algorithms/Deque.h" "Data Structures and Algorithms/Sorting.h" Player.h Question.h)
