cmake_minimum_required(VERSION 3.10.0)
project (ad_da_converter)
add_executable(${PROJECT_NAME} src/ad_da_converter.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
