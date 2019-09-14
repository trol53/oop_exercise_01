cmake_minimum_required(VERSION 3.5)

project(lab1)

add_executable(oop_exercise_01 main.cpp)
set_target_properties(main PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	)
