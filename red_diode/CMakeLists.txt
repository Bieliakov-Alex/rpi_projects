cmake_minimum_required(VERSION 3.10.0)
project (red_diode)
add_executable(${PROJECT_NAME} red_diode.c)
target_link_libraries(${PROJECT_NAME} wiringPi)

