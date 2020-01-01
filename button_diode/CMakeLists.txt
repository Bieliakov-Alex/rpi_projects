cmake_minimum_required(VERSION 3.10.0)
project (button_diode)
add_executable(${PROJECT_NAME} button_diode.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
