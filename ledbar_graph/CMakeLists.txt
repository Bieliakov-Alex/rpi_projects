cmake_minimum_required(VERSION 3.10.0)
project (ledbar_graph)
add_executable(${PROJECT_NAME} src/ledbar_graph.c)
target_link_libraries(${PROJECT_NAME} wiringPi)
