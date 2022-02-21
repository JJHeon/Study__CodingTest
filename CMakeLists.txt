# Cmake Minimum required version 3.16.3
cmake_minimum_required(VERSION 3.0)


# Project Info
project(
    CodingTest
    VERSION 1.0
    DESCRIPTION "Build the selcted codes"
    LANGUAGES CXX)

add_definitions("-g -Wall -std=c++17")
# Test CMake ---------------------------------------------------------------------------------
add_executable(cmake_test cmake_test/main.cc)

# Useful library ---------------------------------------------------------------------------------
# input_reader 22.02.21 
add_library(_input_reader STATIC ${CMAKE_SOURCE_DIR}/library/src/input_reader/input_reader.cc)
target_include_directories(_input_reader PUBLIC ${CMAKE_SOURCE_DIR}/library/src)
target_compile_options(_input_reader PUBLIC -Wall -Werror)

# BackJoon Problams ---------------------------------------------------------------------------------
# Samsung SW CodingTest 기출 문제
add_executable(backjoon-3190 backjoon/3190-Snake.cpp)               #21.01.06	#뱀 
add_executable(backjoon-12100 backjoon/12100-2048.cpp)              #21.01.07	#2048
add_executable(backjoon-13458 backjoon/13458-TestSupervisor.cpp)    #21.02.02	#시험 감독
add_executable(backjoon-13460 backjoon/13460-ExitBead.cpp)          #21.02.02	#구슬 탈출2
add_executable(backjoon-14499 backjoon/14499-RollDice.cpp)          #21.02.02	#주사위 굴리기
add_executable(backjoon-14500 backjoon/14500-Tetronomino.cpp)       #21.02.04	#테트로미노
add_executable(backjoon-14501 backjoon/14501-Resigned.cpp)          #21.02.06	#퇴사
add_executable(backjoon-14502 backjoon/14502-ResearchCenter.cpp)    #21.02.07	#연구소
add_executable(backjoon-14503 backjoon/14503-RobotCleaner.cpp)      #21.02.07	#로봇 청소기
add_executable(backjoon-14888 backjoon/14888-AddOperator.cpp)       #21.02.07	#연산자 끼워넣기
add_executable(backjoon-14889 backjoon/14889-StartAndLink.cpp)      #21.02.08	#스타트와 링크
add_executable(backjoon-14890 backjoon/14890-Slope.cpp)             #21.02.09	#경사로
add_executable(backjoon-14891 backjoon/14891-Gear.cpp)              #21.02.09	#톱니바퀴
add_executable(backjoon-15683 backjoon/15683-Surveillance.cpp)      #21.02.11	#감시
add_executable(backjoon-15684 backjoon/15684-ControlLadder.cpp)     #21.02.11	#사다리 조작
add_executable(backjoon-15685 backjoon/15685-DragonCurve.cpp)       #21.02.11	#드래곤 커브
add_executable(backjoon-15686 backjoon/15686-DeliveryChicken.cpp)   #21.02.11	#치킨 배달
add_executable(backjoon-5373 backjoon/5373-Cubing)                  #21.02.23	#큐빙      
add_executable(backjoon-16234 backjoon/16234-MovePopulation.cpp)    #21.02.27	#인구이동
add_executable(backjoon-16235 backjoon/16235-ZaetechTree.cpp)       #21.03.18	#나무 재태크


