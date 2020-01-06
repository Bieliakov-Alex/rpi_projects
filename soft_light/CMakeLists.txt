cmake_minimum_required(VERSION 3.10.0)
project (soft_light)
add_executable(${PROJECT_NAME} src/soft_light.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
