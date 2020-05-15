cmake_minimum_required(VERSION 3.13)
project(PAT)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wno-c++17-extensions)

file(GLOB src *.cpp)
foreach(file ${src})
	get_filename_component(num ${file} NAME_WE)
	add_executable(${num} ${file})
endforeach()
