cmake_minimum_required(VERSION 3.10.0)
project (pull_up_button)
add_executable(${PROJECT_NAME} src/pull_up_button.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
