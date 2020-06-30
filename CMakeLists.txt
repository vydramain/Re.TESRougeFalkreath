cmake_minimum_required(VERSION 3.12)
project(re.TESRougeFalkreath)

set(CMAKE_CXX_STANDARD 14)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

find_package(BearLibTerminal REQUIRED)
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/includes)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.hpp)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(test)

file(GLOB HEADERS)
#add_executable(${PROJECT_NAME} ./src/main.cpp)
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${BLT_LIBRARIES})
file(COPY ${BLT_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(FILES ${HEADERS} DESTINATION includes/${PROJECT_NAME})
