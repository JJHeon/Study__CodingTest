# Cmake Minimum required version 3.16.3
cmake_minimum_required(VERSION 3.0)


# Project Info
project(
    CodingTest
    VERSION 1.0
    DESCRIPTION "Build the selcted codes"
    LANGUAGES CXX)

add_definitions("-g -Wall -std=c++17")

# Varaible
set(OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,stack-size=1274976")

# Useful library ---------------------------------------------------------------------------------
# input_reader 22.02.21 
add_library(_input_reader STATIC ${CMAKE_SOURCE_DIR}/library/src/input_reader/input_reader.cc)
target_include_directories(_input_reader PUBLIC ${CMAKE_SOURCE_DIR}/library/src)
target_compile_options(_input_reader PUBLIC -Wall)


# Test CMake ---------------------------------------------------------------------------------
# 1 cmake test
add_executable(cmake_test-1 cmake_test/main.cc)

# 2 _input_reader library
add_executable(cmake_test-2 cmake_test/main-2.cc)
target_include_directories(cmake_test-2 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)
target_link_libraries(cmake_test-2 PRIVATE _input_reader)

# 3 Template Test
add_executable(test_template backjoon/test_template.cc)
target_include_directories(test_template PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)
target_link_libraries(test_template PUBLIC _input_reader)

# 4 Test the Code piece
add_executable(test_somecode backjoon/test_somecode.cc)

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

# Apply library Version 1.0
add_executable(backjoon-9251 backjoon/9251-LCS.cc)                                                        #22.03.01 #LCS
target_link_libraries(backjoon-9251 PUBLIC _input_reader)
target_include_directories(backjoon-9251 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-1912 backjoon/1912-ContinuousSum.cc)                                              #22.03.01 #연속합
target_link_libraries(backjoon-1912 PUBLIC _input_reader)
target_include_directories(backjoon-1912 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-12865 backjoon/12865-OrdinaryBackpack.cc)                                         #22.03.05 #평범한 배낭
target_link_libraries(backjoon-12865 PUBLIC _input_reader)
target_include_directories(backjoon-12865 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-1003 backjoon/1003-fibonazzi_function.cc)                                         #22.03.12 #fibonazzi 함수
target_link_libraries(backjoon-1003 PUBLIC _input_reader)
target_include_directories(backjoon-1003 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

# I encount the bugs for the input_reader library Version 1.0, So decide not to use library. #22.03.01
# free compile version
add_executable(backjoon-15649 backjoon/15649-NandM.cc)              #22.03.13
add_executable(backjoon-15650 backjoon/15650-NandM_2.cc)            #22.03.13


