cmake_minimum_required(VERSION 3.29)

project(main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(SRC "src")
set(THREADS "threads")

# disable warnings
add_definitions(-w)

find_package(json-c CONFIG)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${SRC}/LinkedList/linkedList.c
    ${SRC}/http.c
    ${SRC}/main.c
    ${SRC}/thread.c
)

target_link_libraries(${PROJECT_NAME}
    -lcurl
    -ljson-c
    -lpthread
    json-c::json-c
    mysqlclient
)
