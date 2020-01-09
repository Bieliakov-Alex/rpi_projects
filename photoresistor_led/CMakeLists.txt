cmake_minimum_required(VERSION 3.10.0)
project (photoresistor_led)
add_executable(${PROJECT_NAME} src/photoresistor_led.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
