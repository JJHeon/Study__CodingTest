# Cmake Minimum required version 3.16.3
cmake_minimum_required(VERSION 3.0)


# Project Info
project(
    CodingTest
    VERSION 1.0
    DESCRIPTION "Build the selcted codes"
    LANGUAGES CXX)

add_definitions("-Wall -std=c++17")

# Test CMake
add_executable(cmake_test cmake_test/main.cc)


# BackJoon Problams
add_executable(backjoon-3190 backjoon/3190-Snake.cpp)
add_executable(backjoon-5373 backjoon/5373-Cubing)
add_executable(backjoon-12100 backjoon/12100-2048.cpp)
add_executable(backjoon-13458 backjoon/13458-TestSupervisor.cpp)
add_executable(backjoon-13460 backjoon/13460-ExitBead.cpp)
add_executable(backjoon-14499 backjoon/14499-RollDice.cpp)
add_executable(backjoon-14500 backjoon/14500-Tetronomino.cpp)
add_executable(backjoon-14501 backjoon/14501-Resigned.cpp)
add_executable(backjoon-14502 backjoon/14502-ResearchCenter.cpp)
add_executable(backjoon-14503 backjoon/14503-RobotCleaner.cpp)
add_executable(backjoon-14888 backjoon/14888-AddOperator.cpp)
add_executable(backjoon-14889 backjoon/14889-StartAndLink.cpp)
add_executable(backjoon-14890 backjoon/14890-Slope.cpp)
add_executable(backjoon-14891 backjoon/14891-Gear.cpp)
add_executable(backjoon-15683 backjoon/15683-Surveillance.cpp)
add_executable(backjoon-15684 backjoon/15684-ControlLadder.cpp)
add_executable(backjoon-15685 backjoon/15685-DragonCurve.cpp)
add_executable(backjoon-15686 backjoon/15686-DeliveryChicken.cpp)
add_executable(backjoon-16234 backjoon/16234-MovePopulation.cpp)
add_executable(backjoon-16235 backjoon/16235-ZaetechTree.cpp)


