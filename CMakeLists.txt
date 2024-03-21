cmake_minimum_required(VERSION 3.10) 
project(TicTacToe VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TicTacToe src/main.cpp src/ticTacToe.cpp)

target_include_directories(TicTacToe PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/lib")

add_custom_target(run
    COMMAND TicTacToe
    DEPENDS TicTacToe  
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)