cmake_minimum_required(VERSION 3.14)
project(Mosquitto_subscriber_Example)

set(CMAKE_CXX_STANDARD 17)

link_directories(
        /usr/lib/x86_64-linux-gnu/
)

include_directories(
        /usr/include
)

add_executable(Mosquitto_subscriber_Example main.cpp mqtt_wrapper/mqtt_wrapper.cpp)

target_link_libraries(Mosquitto_subscriber_Example mosquitto)