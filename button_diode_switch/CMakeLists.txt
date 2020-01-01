cmake_minimum_required(VERSION 3.10.0)
project (button_diode_switch)
add_executable(${PROJECT_NAME} src/button_diode_switch.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
