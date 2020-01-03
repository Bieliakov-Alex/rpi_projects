cmake_minimum_required(VERSION 3.10.0)
project (doorbell)
add_executable(${PROJECT_NAME} src/doorbell.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
