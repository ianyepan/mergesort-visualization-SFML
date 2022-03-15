cmake_minimum_required(VERSION 3.14)

# Get project name from folder name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

set(SOURCES src/Main.cpp src/Bar.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(src)
include_directories(include)

configure_file(res/OpenSans-Regular.ttf OpenSans-Regular.ttf COPYONLY)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(SFML/include)
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "a.out")
