cmake_minimum_required(VERSION 3.10.2)
project(poo2_unit6_2020_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${OUTPUT_DEBUG})

add_executable(poo2_unit6_2020_2
        main.cpp
        test_1.cpp
        test_2.cpp
        test_3.cpp
        test_4.cpp
        test_5.cpp
        test_6.cpp
        test_7.cpp
        test_8.cpp
        p1.cpp p1.h
        p2.cpp p2.h
        p3.cpp p3.h
        p4.cpp p4.h
        p5.cpp p5.h
        p6.cpp p6.h
        p7.cpp p7.h
        p8.cpp p8.h
        graph.h
        binary_tree.h)

configure_file(test_1.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_2.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_3.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_4.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_5.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_6.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_7.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
configure_file(test_8.in ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} COPYONLY)
