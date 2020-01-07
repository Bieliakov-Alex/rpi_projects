cmake_minimum_required(VERSION 3.10.0)
project (soft_rgb)
add_executable(${PROJECT_NAME} src/soft_rgb.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
