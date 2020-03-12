cmake_minimum_required(VERSION 3.0)
project(beetle)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

include_directories(include)

file(GLOB_RECURSE main ./src/main/*.h ./src/main/*.cpp)
file(GLOB_RECURSE tests ./src/test/*.cpp ./src/main/*.h ./src/main/Fruit.cpp ./src/main/Game.cpp ./src/main/Player.cpp ./src/main/Snake.cpp ./src/main/Type.cpp)

IF (GENERATE_CODE_COVERAGE)
    message(STATUS "Compiling with code coverage")
    SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
    SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
ENDIF()

add_executable(tests
        ${tests})
target_link_libraries(tests ${CMAKE_THREAD_LIBS_INIT})

add_executable(program
        ${main})
target_link_libraries(program ${CMAKE_THREAD_LIBS_INIT})


IF (GENERATE_CODE_COVERAGE)
    target_link_libraries(tests gcov)
ENDIF()
