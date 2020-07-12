cmake_minimum_required(VERSION 3.10)
project(re.TESRougeFalkreath)

set(CMAKE_CXX_STANDARD 14)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

find_package(BearLibTerminal REQUIRED)
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})


set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.hpp)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)
include_directories(${PROJECT_HEADERS_DIR})


set (TESTS_SOURCES tests/test.cpp)

#set (CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "lib/Boost/include/boost")
#set (CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "lib/Boost/include/boost/lib")
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set (TEST re.TEST${PROJECT})
add_executable (${TEST} ${TESTS_SOURCES})
target_link_libraries (${TEST} ${PROJECT} ${Boost_LIBRARIES})
enable_testing ()
add_test (${TEST} ${TEST})

file(GLOB HEADERS)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${BLT_LIBRARIES})
file(COPY ${BLT_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
