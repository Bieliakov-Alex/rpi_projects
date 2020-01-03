cmake_minimum_required(VERSION 3.10.0)
project (alertor)
add_executable(${PROJECT_NAME} src/alertor.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
