cmake_minimum_required(VERSION 2.6)
project(ZadanieDlaP)
SET(CMAKE_CXX_FLAGS "-std=c++0x -pthread -Wall")
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/include")
add_library(tinyxml2 SHARED ${CMAKE_CURRENT_SOURCE_DIR}/external/tinyXML/tinyxml2.h ${CMAKE_CURRENT_SOURCE_DIR}/external/tinyXML/tinyxml2.cpp)
SET( NAME_SRC
    src/main.cpp
    src/shapefactory.cpp
    src/triangle.cpp
    src/rectangle.cpp
)
add_executable(ZadanieDlaP ${NAME_SRC})
target_link_libraries(ZadanieDlaP tinyxml2)
