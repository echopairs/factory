cmake_minimum_required(VERSION 3.5)
project(tasks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

include_directories(${tasks_SOURCE_DIR}/include)
include_directories(${tasks_SOURCE_DIR})

set(SOURCE_FILES main.cpp
        src/process/process.cpp
        src/process/process.h
        src/process/runner.h
        src/process/runner.cpp
        src/Ifactory/IFactory.h
        src/Ifactory/ITask.h
        src/url/url_factory.cpp
        src/url/url_factory.h
        src/url/url_task.h
        src/url/url_task.cpp
        src/url/url_runner.h
        src/url/url_runner.cpp
        include/utils/time.h)
add_executable(tasks ${SOURCE_FILES})
target_link_libraries(tasks pthread)