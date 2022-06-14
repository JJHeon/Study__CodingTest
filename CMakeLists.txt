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
add_executable(test_somecode tmp_test/somecode.cc)
add_executable(test_tmpmain tmp_test/tmpmain.cc)

# BackJoon Problams ---------------------------------------------------------------------------------
# Samsung SW CodingTest 기출 문제
add_executable(backjoon-3190 backjoon/3190-Snake.cpp) # 21.01.06	#뱀
add_executable(backjoon-12100 backjoon/12100-2048.cpp) # 21.01.07	#2048
add_executable(backjoon-13458 backjoon/13458-TestSupervisor.cpp) # 21.02.02	#시험 감독
add_executable(backjoon-13460 backjoon/13460-ExitBead.cpp) # 21.02.02	#구슬 탈출2
add_executable(backjoon-14499 backjoon/14499-RollDice.cpp) # 21.02.02	#주사위 굴리기
add_executable(backjoon-14500 backjoon/14500-Tetronomino.cpp) # 21.02.04	#테트로미노
add_executable(backjoon-14501 backjoon/14501-Resigned.cpp) # 21.02.06	#퇴사
add_executable(backjoon-14502 backjoon/14502-ResearchCenter.cpp) # 21.02.07	#연구소
add_executable(backjoon-14503 backjoon/14503-RobotCleaner.cpp) # 21.02.07	#로봇 청소기
add_executable(backjoon-14888 backjoon/14888-AddOperator.cpp) # 21.02.07	#연산자 끼워넣기
add_executable(backjoon-14889 backjoon/14889-StartAndLink.cpp) # 21.02.08	#스타트와 링크
add_executable(backjoon-14890 backjoon/14890-Slope.cpp) # 21.02.09	#경사로
add_executable(backjoon-14891 backjoon/14891-Gear.cpp) # 21.02.09	#톱니바퀴
add_executable(backjoon-15683 backjoon/15683-Surveillance.cpp) # 21.02.11	#감시
add_executable(backjoon-15684 backjoon/15684-ControlLadder.cpp) # 21.02.11	#사다리 조작
add_executable(backjoon-15685 backjoon/15685-DragonCurve.cpp) # 21.02.11	#드래곤 커브
add_executable(backjoon-15686 backjoon/15686-DeliveryChicken.cpp) # 21.02.11	#치킨 배달
add_executable(backjoon-5373 backjoon/5373-Cubing) # 21.02.23	#큐빙
add_executable(backjoon-16234 backjoon/16234-MovePopulation.cpp) # 21.02.27	#인구이동
add_executable(backjoon-16235 backjoon/16235-ZaetechTree.cpp) # 21.03.18	#나무 재태크

# Apply library Version 1.0
add_executable(backjoon-9251 backjoon/9251-LCS.cc) # 22.03.01 #LCS
target_link_libraries(backjoon-9251 PUBLIC _input_reader)
target_include_directories(backjoon-9251 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-1912 backjoon/1912-ContinuousSum.cc) # 22.03.01 #연속합
target_link_libraries(backjoon-1912 PUBLIC _input_reader)
target_include_directories(backjoon-1912 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-12865 backjoon/12865-OrdinaryBackpack.cc) # 22.03.05 #평범한 배낭
target_link_libraries(backjoon-12865 PUBLIC _input_reader)
target_include_directories(backjoon-12865 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

add_executable(backjoon-1003 backjoon/1003-fibonazzi_function.cc) # 22.03.12 #fibonazzi 함수
target_link_libraries(backjoon-1003 PUBLIC _input_reader)
target_include_directories(backjoon-1003 PUBLIC ${CMAKE_SOURCE_DIR}/library/src/input_reader)

# I encount the bugs for the input_reader library Version 1.0, So decide not to use library. #22.03.01
# free compile version
add_executable(backjoon-15649 backjoon/15649-NandM.cc) # 22.03.13
add_executable(backjoon-15650 backjoon/15650-NandM_2.cc) # 22.03.13
add_executable(backjoon-15651 backjoon/15651-NandM_3.cc) # 22.03.13
add_executable(backjoon-15652 backjoon/15652-NandM_4.cc) # 22.03.13
add_executable(backjoon-9663 backjoon/9663-N_Queen.cc) # 22.03.13
add_executable(backjoon-2580 backjoon/2580-Sudoku.cc) # 22.03.15
add_executable(backjoon-11654 backjoon/11654-AsciiCode.cc) # 22.03.15
add_executable(backjoon-11720 backjoon/11720-SumOfNumbers.cc) # 22.03.16
add_executable(backjoon-10809 backjoon/10809-SearchAlphabet.cc) # 22.03.16
add_executable(backjoon-2675 backjoon/2675-RepeatString.cc) # 22.03.16
add_executable(backjoon-1157 backjoon/1157-WordStudy.cc) # 22.03.16
add_executable(backjoon-1152 backjoon/1152-NumberOfWord.cc) # 22.03.16
add_executable(backjoon-2908 backjoon/2908-Constant.cc) # 22.03.17
add_executable(backjoon-5622 backjoon/5622-Dial.cc) # 22.03.17
add_executable(backjoon-2941 backjoon/2941-CroatiaAlphabet.cc) # 22.03.17
add_executable(backjoon-1316 backjoon/1316-GroupWordChecker.cc) # 22.03.21
add_executable(backjoon-11047 backjoon/11047-CoinZero.cc) # 22.03.22
add_executable(backjoon-1931 backjoon/1931-AssignMeetingRoom.cc) # 22.03.22
add_executable(backjoon-11399 backjoon/11399-ATM.cc) # 22.03.23
add_executable(backjoon-1541 backjoon/1541-LostParentheses.cc) # 22.03.23
add_executable(backjoon-13305 backjoon/13305-GasStation.cc) # 22.03.24

add_executable(real programmers/00048-Friends4Block.cc) # test

# Probrammers Problams ---------------------------------------------------------------------------------
# 00001-UnfinishedPlayer.cc 완주하지 못한 선수                      #22.03.24
# 00003-Camouflage.cc 위장                                          #22.03.29
# 00004-BestAlbum.cc 베스트앨범                                     #22.03.29
# 00005-JoggingSuit.cc 체육복                                       #22.03.30
# 00006-Joystick.cc 조이스틱                                        #22.04.16
# 00007-MakeBigNumber.cc 큰 수 만들기                               #22.04.16
# 00008-Lifeboat.cc 구명보트                                        #22.04.17

# 00010-CompressString.cc 문자열 압축                               #22.04.28
# 00011-KaKaoFriendsColoringBook.cc 카카오프렌즈 컬러링북           #22.04.29
# 00012-OpenChatRoom.cc 오픈채팅방                                  #22.05.05
# 00013-TakeGroupPhoto.cc 단체사진 찍기                             #22.05.06

# 00015-DevelopFunction.cc 기능개발                                 #22.05.09
# 00016-TargetNumber.cc 타겟넘버                                    #22.05.09
# 00017-MakePairAndErase.cc 짝지어 제거하기                         #22.05.10
# 00018-RotateMatrixBoarder.cc 행렬 테두리 회전하기                 #22.05.11
# 00019-MenuRenewer.cc 메뉴 리뉴얼                                  #22.06.09
# 00020-ConvertParenthesis.cc 괄호 변환                             #22.05.16
# 00021-CheckKeepingDistance.cc 거리두기 확인하기                   #22.05.16
# 00022-ReceiveReportResult.cc 신고결과 받기                        #22.05.17
# 00023-MaximizationEquation.cc 수식 최대화                         #22.05.17
# 00024-HighstRankAndLowerRankInLotto.cc 로또의 최고순위와 최저순위 #22.05.17
# 00025-PathOfLightCycle.cc 빛의 경로 사이클                        #22.05.18
# 00026-Printer.cc 프린터                                           #22.05.18
# 00027-SearchRanking.cc 순위 검색                                  #22.06.09
# 00028-ShortestPathInGameMap.cc 게임 맵 최단 거리                  #22.05.23
# 00029-NewsClustering.cc 뉴스 클러스터링                           #22.05.23
# 00030-MoreSpicy.cc 더 맵게                                        #22.05.23
# 00031-StackPrice.cc 주식가격                                      #22.05.24
# 00032-TruckThatCrossUnderBridge.cc 다리를 지나는 트럭             #22.05.24
# 00033-PredictableConfrontationTable.cc 예상 대진표                #22.05.25
# 00034-Carpet.cc 카펫                                              #22.05.25
# 00035-Tuple.cc 튜플                                               #22.05.25
# 00036-ExhaustedDegree.cc 피로도                                   #22.05.25
# 00037-CalcultateParkingFee.cc 주차 요금 계산                      #22.05.25
# 00038-SecondaryKey.cc 후보키                                      #22.06.10
# 00039-TtangTtameoKgi.cc 땅따먹기                                  #22.05.30
# 00040-NextBigNumber.cc 다음 큰 숫자                               #22.05.30
# 00041-BiggestNumber.cc 가장 큰 수                                 #22.06.07
# 00042-2xnTiling.cc 2xn 타일링                                     #22.06.07
# 00043-HIndex.cc H-Index                                           #22.06.08
# 00044-Delivery.cc 배달                                            #22.06.08
# 00045-EnglishWordChain.cc 영어 끝말잇기                           #22.06.09
# 00046-DividePowerGrid.cc 전력망을 둘로 나누기                     #22.06.13
# 00047-TriangleSnail.cc 삼각 달팽이                                #22.06.13
# 00048-Friends4Block.cc 프렌즈4블럭                                #22.06.14

# 못푼 문제들
# 00014-124CountryNumber.cc 124 나라의 숫자                         #22.05.06 ~
