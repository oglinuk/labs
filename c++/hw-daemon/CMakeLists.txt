cmake_minimum_required(VERSION 3.10)

project(hw_daemon)

add_executable(
    main 
    main.cpp 
    daemon.h 
    daemon.cpp
)