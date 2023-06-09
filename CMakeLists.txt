cmake_minimum_required(VERSION 3.23)
project(SDL4)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDL4 main.cpp Calculator.cpp Stack.cpp List.cpp Queue.cpp InToPost.cpp Node.cpp)
