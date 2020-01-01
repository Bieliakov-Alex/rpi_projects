cmake_minimum_required(VERSION 3.10.0)
project (red_diode)
target_link_libraries(${PROJECT_NAME} wiringPi)
add_executable(${PROJECT_NAME} red_diode.c)