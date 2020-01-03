cmake_minimum_required(VERSION 3.10.0)
project (rgb_led)
add_executable(${PROJECT_NAME} src/rgb_led.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
