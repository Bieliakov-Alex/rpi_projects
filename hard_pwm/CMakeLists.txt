cmake_minimum_required(VERSION 3.10.0)
project (hard_pwm)
add_executable(${PROJECT_NAME} src/hard_pwm.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
