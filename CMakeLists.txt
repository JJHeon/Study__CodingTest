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

# 5 Test for New TestCodeProvider library
add_executable(test_pro ttt/main.cc) # 22.03.01 #연속합
target_include_directories(test_pro PUBLIC ${CMAKE_SOURCE_DIR}/ttt)

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
add_executable(backjjon-11507 backjoon/11507-CardSet.cc) # 22.06.25 #카드셋트

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
add_executable(backjoon-1260 backjoon/1260-DFSAndBFS.cc) # 22.07.06             #DFS와 BFS
add_executable(backjoon-2178 backjoon/2178-SearchMaze.cc) # 22.07.06            #미로 탐색
add_executable(backjoon-2606 backjoon/2606-Virus.cc) # 22.07.06                 #바이러스
add_executable(backjoon-2667 backjoon/2667-NamingHomeNumber.cc) # 22.07.07      #단지번호붙이기
add_executable(backjoon-2644 backjoon/2644-CalculateDegreeOfKinship.cc) # 22.07.07      #촌수계산
add_executable(backjoon-7569 backjoon/7569-Tomato.cc) # 22.07.13                        #토마토
add_executable(backjoon-1697 backjoon/1697-HideAndSeek.cc) # 22.07.13                   #숨바꼭질
add_executable(backjoon-5014 backjoon/5014-StartLink.cc) # 22.07.13                     #스타트링크
add_executable(backjoon-2468 backjoon/2468-SafeZone.cc) # 22.07.13                      #안전 영역
add_executable(backjoon-2563 backjoon/2563-IceMountain.cc) # 22.07.14                   #빙산
add_executable(backjoon-9205 backjoon/9205-WalkingWithBear.cc) # 22.07.18               #맥주 마시며 걷기
add_executable(backjoon-1747 backjoon/1747-PrimeNumberAndPalindrome.cc) # 22.07.18               #소수&팰린드롬
add_executable(backjoon-2589 backjoon/2589-TreasureIsland.cc) # 22.07.18               #보물섬
add_executable(backjoon-7562 backjoon/7562-MoveOfKnight.cc) # 22.07.18               #나이트의 이동
add_executable(backjoon-7576 backjoon/7576-Tomato.cc) # 22.07.18               #토마토
add_executable(backjoon-2583 backjoon/2583-DrawArea.cc) # 22.07.19               #영역 구하기
add_executable(backjoon-1655 backjoon/1655-SayMiddleNumber.cc) # 22.07.19               #가운데를 말해요
add_executable(backjoon-11050 backjoon/11050-BinomialCoefficient1.cc) # 22.07.19               #이항 계수 1
add_executable(backjoon-11051 backjoon/11051-BinomialCoefficient2.cc) # 22.07.19               #이항 계수 2
add_executable(backjoon-11401 backjoon/11401-BinomialCoefficient3.cc) # 22.07.19               #이항 계수 3
add_executable(backjoon-16954 backjoon/16954-EscapeMovingMaze.cc) # 22.07.19               #움직이는 미로 탈출
add_executable(backjoon-1956 backjoon/1956-Excercise.cc) # 22.07.20               #운동
add_executable(backjoon-6087 backjoon/6087-LaserCommunication.cc) # 22.07.23               #레이저 통신
add_executable(backjoon-7682 backjoon/7682-TickTeckTo.cc) # 22.07.23               #틱택토
add_executable(backjoon-2151 backjoon/2151-SetMirror.cc) # 22.07.23                #거울 설치
add_executable(backjoon-1976 backjoon/1976-GoTrip.cc) # 22.07.23                #여행 가자
add_executable(backjoon-16236 backjoon/16236-BabyShark.cc) # 22.07.23                #아기 상어
add_executable(backjoon-16929 backjoon/16929-TwoDots.cc) # 22.07.24                #Two dots

add_executable(real programmers/00068-JumpFar.cc) # test

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
# 00049-ArcheryCompetition.cc 양궁대회                              #22.06.16
# 00050-LessthanTwoDiffentBit.cc 2개 이하로 다른 비트               #22.06.16
# 00051-Cache.cc 캐시                                               #22.06.20
# 00052-JumpAndTeleport.cc 점프와 순간 이동                          #22.06.21
# 00053-SkillTree.cc 스킬트리                                        #22.06.21
# 00054-VowelDictionary.cc 모음 사전                                 #22.06.21
# 00055-RepeatBinaryTransformation.cc 이진 변환 반복하기              #22.06.21
# 00056-Compress.cc 압축                                             #22.06.21
# 00057-ThatSong.cc 방금그곡                                         #22.06.22
# 00058-SortFileName.cc 파일명 정렬                                  #22.06.22
# 00059-CorrectParenthesis.cc 올바른 괄호                            #22.06.22
# 00060-FindBigestSquare.cc 가장 큰 정사각형 찾기                    #22.07.01
# 00061-FindPrimeNumber.cc 소수 찾기                                 #22.06.16
# 00062-RotateParenthesis.cc 괄호 회전하기                           #22.06.16
# 00064-NnumeralGame.cc n진수 게임                                   #22.07.01
# 00065-VisitedLength.cc 방문 길이                                   #22.07.04
# 00066-NQueen.cc N-Queen                                            #22.07.04

# 00068-JumpFar.cc 멀리 뛰기                                         #22.07.05

# 못푼 문제들
# 00014-124CountryNumber.cc 124 나라의 숫자                         #22.05.06 ~
