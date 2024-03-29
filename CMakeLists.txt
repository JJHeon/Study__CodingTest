# Cmake Settings  ---------------------------------------------------------------------------------
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

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,stack-size=1274976") # MAC OS Problems

# BackJoon  -----------------------------------------------------------------------------------------
# 21.01.06  #03109  #뱀
# 21.01.07  #12100  #2048
# 21.02.02  #13460	#구슬 탈출2
# 21.02.02  #13458	#시험 감독
# 21.02.02  #14499	#주사위 굴리기
# 21.02.04  #14500  #테트로미노
# 21.02.06  #14501	#퇴사
# 21.02.07  #14502	#연구소 #(Renew1 23.02.12)
# 21.02.07  #14503	#로봇 청소기
# 21.02.07  #14888	#연산자 끼워넣기
# 21.02.08  #14889	#스타트와 링크
# 21.02.09  #14890	#경사로
# 21.02.09  #14891	#톱니바퀴
# 21.02.11  #15683	#감시
# 21.02.11  #15684	#사다리 조작
# 21.02.11  #15685	#드래곤 커브
# 21.02.11  #15686	#치킨 배달 #(Renew1 23.01.10)
# 21.02.23  #05373  #큐빙
# 21.02.27  #16235	#인구이동
# 22.06.25  #11507  #카드셋트
# 22.03.01  #09251  #LCS
# 22.03.05  #12865  #평범한 배낭
# 22.03.01  #01912  #연속합
# 22.03.12  #01003  #fibonazzi 함수
# 22.03.13  #15649  #N&M 1
# 22.03.13  #15650  #N&M 2
# 22.03.13  #15651  #N&M 3
# 22.03.13  #15652  #N&M 4
# 22.03.13  #09663  #N Queen
# 22.03.15  #02580  #스도쿠
# 22.03.15  #11654  #아스키코드
# 22.03.16  #11720  #수의 합
# 22.03.16  #10809  #알파벳 찾기
# 22.03.16  #02675  #문자열 반복
# 22.03.16  #01157  #단어 공부
# 22.03.16  #01152  #단어 수
# 22.03.17  #02908  #상수
# 22.03.17  #05622  #다이얼
# 22.03.17  #02941  #크로아티아 알파벳
# 22.03.21  #01316  #단어 그룹 체크
# 22.03.22  #11047  #?
# 22.03.22  #01931  #회의실 예약
# 22.03.23  #11399  #ATM
# 22.03.23  #01541  #잃어버린 괄호
# 22.03.24  #13305  #주유소
# 22.07.06  #01260  #DFS와 BFS
# 22.07.06  #02178  #미로 탐색
# 22.07.06  #02606  #바이러스
# 22.07.07  #02667  #번호붙이기
# 22.07.07  #02644  #촌수계산
# 22.07.13  #07569  #토마토
# 22.07.13  #01697  #숨바꼭질
# 22.07.13  #05014  #스타트링크
# 22.07.13  #02468  #안전 영역
# 22.07.14  #02563  #빙산
# 22.07.18  #09205  #맥주 마시며 걷기
# 22.07.18  #01747  #소수&팰린드롬
# 22.07.18  #02589  #보물섬 #(Renew1 23.02.13)
# 22.07.18  #07562  #나이트의 이동
# 22.07.18  #07576  #토마토
# 22.07.19  #02583  #영역 구하기 #(Renew1 23.02.06) #(Renew2 23.02.06)
# 22.07.19  #01655  #가운데를 말해요
# 22.07.19  #11050  #이항 계수 1
# 22.07.19  #11051  #이항 계수 2
# 22.07.19  #16954  #움직이는 미로 탈출
# 22.07.20  #01956  #운동
# 22.07.23  #06087  #레이저 통신
# 22.07.23  #07682  #틱택토
# 22.07.23  #02151  #거울 설치
# 22.07.23  #01976  #여행 가자
# 22.07.23  #16236  #아기 상어
# 22.07.24  #16929  #Two dots
# 22.07.24  #03055  #탈출
# 22.07.27  #17836  #공주님을 구해라!
# 22.07.28  #02234  #성곽
# 22.07.28  #17244  #아맞다우산
# 22.08.01  #05427  #불
# 22.08.02  #02668  #숫자고르기

# BackJoon Unfinished
# 22.07.19  #11401  #이항 계수 3

# Probrammers Problams ------------------------------------------------------------------------------------
add_executable(real programmers/00068-JumpFar.cc)

# 22.03.24  #00001-UnfinishedPlayer.cc 완주하지 못한 선수
# 22.03.29  #00003-Camouflage.cc 위장
# 22.03.29  #00004-BestAlbum.cc 베스트앨범
# 22.03.30  #00005-JoggingSuit.cc 체육복
# 22.04.16  #00006-Joystick.cc 조이스틱
# 22.04.16  #00007-MakeBigNumber.cc 큰 수 만들기
# 22.04.17  #00008-Lifeboat.cc 구명보트
# 22.04.28  #00010-CompressString.cc 문자열 압축
# 22.04.29  #00011-KaKaoFriendsColoringBook.cc 카카오프렌즈 컬러링북
# 22.05.05  #00012-OpenChatRoom.cc 오픈채팅방
# 22.05.06  #00013-TakeGroupPhoto.cc 단체사진 찍기
# 22.05.09  #00015-DevelopFunction.cc 기능개발
# 22.05.09  #00016-TargetNumber.cc 타겟넘버
# 22.05.10  #00017-MakePairAndErase.cc 짝지어 제거하기
# 22.05.11  #00018-RotateMatrixBoarder.cc 행렬 테두리 회전하기
# 22.06.09  #00019-MenuRenewer.cc 메뉴 리뉴얼
# 22.05.16  #00020-ConvertParenthesis.cc 괄호 변환
# 22.05.16  #00021-CheckKeepingDistance.cc 거리두기 확인하기
# 22.05.17  #00022-ReceiveReportResult.cc 신고결과 받기
# 22.05.17  #00023-MaximizationEquation.cc 수식 최대화
# 22.05.17  #00024-HighstRankAndLowerRankInLotto.cc 로또의 최고순위와 최저순위
# 22.05.18  #00025-PathOfLightCycle.cc 빛의 경로 사이클
# 22.05.18  #00026-Printer.cc 프린터
# 22.06.09  #00027-SearchRanking.cc 순위 검색
# 22.05.23  #00028-ShortestPathInGameMap.cc 게임 맵 최단 거리
# 22.05.23  #00029-NewsClustering.cc 뉴스 클러스터링
# 22.05.23  #00030-MoreSpicy.cc 더 맵게
# 22.05.24  #00031-StackPrice.cc 주식가격
# 22.05.24  #00032-TruckThatCrossUnderBridge.cc 다리를 지나는 트럭
# 22.05.25  #00033-PredictableConfrontationTable.cc 예상 대진표
# 22.05.25  #00034-Carpet.cc 카펫
# 22.05.25  #00035-Tuple.cc 튜플
# 22.05.25  #00036-ExhaustedDegree.cc 피로도
# 22.05.25  #00037-CalcultateParkingFee.cc 주차 요금 계산
# 22.06.10  #00038-SecondaryKey.cc 후보키
# 22.05.30  #00039-TtangTtameoKgi.cc 땅따먹기
# 22.05.30  #00040-NextBigNumber.cc 다음 큰 숫자
# 22.06.07  #00041-BiggestNumber.cc 가장 큰 수
# 22.06.07  #00042-2xnTiling.cc 2xn 타일링
# 22.06.08  #00043-HIndex.cc H-Index
# 22.06.08  #00044-Delivery.cc 배달
# 22.06.09  #00045-EnglishWordChain.cc 영어 끝말잇기
# 22.06.13  #00046-DividePowerGrid.cc 전력망을 둘로 나누기
# 22.06.13  #00047-TriangleSnail.cc 삼각 달팽이
# 22.06.14  #00048-Friends4Block.cc 프렌즈4블럭
# 22.06.16  #00049-ArcheryCompetition.cc 양궁대회
# 22.06.16  #00050-LessthanTwoDiffentBit.cc 2개 이하로 다른 비트
# 22.06.20  #00051-Cache.cc 캐시
# 22.06.21  #00052-JumpAndTeleport.cc 점프와 순간 이동
# 22.06.21  #00053-SkillTree.cc 스킬트리
# 22.06.21  #00054-VowelDictionary.cc 모음 사전
# 22.06.21  #00055-RepeatBinaryTransformation.cc 이진 변환 반복하기
# 22.06.21  #00056-Compress.cc 압축
# 22.06.22  #00057-ThatSong.cc 방금그곡
# 22.06.22  #00058-SortFileName.cc 파일명 정렬
# 22.06.22  #00059-CorrectParenthesis.cc 올바른 괄호
# 22.07.01  #00060-FindBigestSquare.cc 가장 큰 정사각형 찾기
# 22.06.16  #00061-FindPrimeNumber.cc 소수 찾기
# 22.06.16  #00062-RotateParenthesis.cc 괄호 회전하기
# 22.07.01  #00064-NnumeralGame.cc n진수 게임
# 22.07.04  #00065-VisitedLength.cc 방문 길이
# 22.07.04  #00066-NQueen.cc N-Queen
# 22.07.05  #00068-JumpFar.cc 멀리 뛰기

# # Probrammers Unfished
# #00014-124CountryNumber.cc 124 나라의 숫자
# #00063-MakeStarInIntersection.cc
# #00067-FineSquare.cc
# 00069-ChusoekTraffic.cc

# Problams -----------------------------------------------------------------------------------------
add_executable(backjoon-3190 backjoon/3190-Snake.cpp) # 21.01.06  #뱀 #(Renew1 23.03.11)
add_executable(backjoon-12100 backjoon/12100-2048.cpp) # 21.01.07  #2048 #(Renew1 23.03.11)
add_executable(backjoon-13458 backjoon/13458-TestSupervisor.cpp) # 21.02.02	#시험 감독
add_executable(backjoon-13460 backjoon/13460-ExitBead.cpp) # 21.02.02	#구슬 탈출2
add_executable(backjoon-14499 backjoon/14499-RollDice.cpp) # 21.02.02	#주사위 굴리기
add_executable(backjoon-14500 backjoon/14500-Tetronomino.cpp) # 21.02.04  #테트로미노
add_executable(backjoon-14501 backjoon/14501-Resigned.cpp) # 21.02.06	#퇴사
add_executable(backjoon-14502 backjoon/14502-ResearchCenter.cpp) # 21.02.07	#연구소 #(Renew1 23.02.12)
add_executable(backjoon-14503 backjoon/14503-RobotCleaner.cpp) # 21.02.07	#로봇 청소기
add_executable(backjoon-14888 backjoon/14888-AddOperator.cpp) # 21.02.07	#연산자 끼워넣기 #(Renew1 23.03.18)
add_executable(backjoon-14889 backjoon/14889-StartAndLink.cpp) # 21.02.08	#스타트와 링크 #(Renew1 23.03.10)
add_executable(backjoon-14890 backjoon/14890-Slope.cpp) # 21.02.09	#경사로 #(Renew1 23.02.22)
add_executable(backjoon-14891 backjoon/14891-Gear.cpp) # 21.02.09	#톱니바퀴
add_executable(backjoon-15683 backjoon/15683-Surveillance.cpp) # 21.02.11	#감시 #(Renew1 23.03.20)
add_executable(backjoon-15684 backjoon/15684-ControlLadder.cpp) # 21.02.11	#사다리 조작 #(Renew1 23.02.20)
add_executable(backjoon-15685 backjoon/15685-DragonCurve.cpp) # 21.02.11	#드래곤 커브 #(Renew1 23.03.19)
add_executable(backjoon-15686 backjoon/15686-DeliveryChicken.cpp) # 21.02.11	#치킨 배달 #(Renew1 23.01.10)
add_executable(backjoon-5373 backjoon/5373-Cubing.cpp) # 21.02.23  #큐빙
add_executable(backjoon-16234 backjoon/16234-MovePopulation.cpp) # 21.02.27	#인구이동 #(Renew1 23.02.13)
add_executable(backjoon-16235 backjoon/16235-ZaetechTree.cpp) # 21.03.18	#나무 재태크
add_executable(backjoon-9251 backjoon/9251-LCS.cc) # 22.03.01 #LCS
add_executable(backjoon-12865 backjoon/12865-OrdinaryBackpack.cc) # 22.03.05 #평범한 배낭
add_executable(backjoon-1912 backjoon/1912-ContinuousSum.cc) # 22.03.01 #연속합 #(Renew1 23.03.20)
add_executable(backjoon-1003 backjoon/1003-fibonazzi_function.cc) # 22.03.12 #fibonazzi 함수
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
add_executable(backjoon-1931 backjoon/1931-AssignMeetingRoom.cc) # 22.03.22     #(Renew1 23.03.07) #(Renew2 23.03.07)
add_executable(backjoon-11399 backjoon/11399-ATM.cc) # 22.03.23
add_executable(backjoon-1541 backjoon/1541-LostParentheses.cc) # 22.03.23
add_executable(backjoon-13305 backjoon/13305-GasStation.cc) # 22.03.24
add_executable(backjjon-11507 backjoon/11507-CardSet.cc) # 22.06.25 #카드셋트
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
add_executable(backjoon-2589 backjoon/2589-TreasureIsland.cc) # 22.07.18               #보물섬 #(Renew1 23.02.13)
add_executable(backjoon-7562 backjoon/7562-MoveOfKnight.cc) # 22.07.18               #나이트의 이동
add_executable(backjoon-7576 backjoon/7576-Tomato.cc) # 22.07.18               #토마토
add_executable(backjoon-2583 backjoon/2583-DrawArea.cc) # 22.07.19               #영역 구하기 #(Renew1 23.02.06) #(Renew2 23.02.06)
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
add_executable(backjoon-3055 backjoon/3055-Escape.cc) # 22.07.24                #탈출
add_executable(backjoon-17836 backjoon/17836-RescuePrincess.cc) # 22.07.27                #공주님을 구해라!
add_executable(backjoon-2234 backjoon/2234-Fortress.cc) # 22.07.28                #성곽 #(Renew1 23.02.25)
add_executable(backjoon-17244 backjoon/17244-AMatThaUooSan.cc) # 22.07.28                #아맞다우산
add_executable(backjoon-5427 backjoon/5427-Fire.cc) # 22.08.01                #불
add_executable(backjoon-2668 backjoon/2668-PickNumber.cc) # 22.08.02                #숫자고르기
add_executable(backjoon-1920 backjoon/1920-FindNumber.cc) # 22.10.07                #수 찾기
add_executable(backjoon-17144 backjoon/17144-GoodbyeDust.cc) # 22.10.07                #미세먼지 안녕 #Renew1(23.03.09)
add_executable(backjoon-17143 backjoon/17143-FishingKing.cc) # 22.10.07                #낚시왕 #Renew1(23.03.18)
add_executable(backjoon-17140 backjoon/17140-2DimensionArrayAndCalulate.cc) # 22.10.17                #이차원 배열과 연산
add_executable(backjoon-17142 backjoon/17142-Lab3.cc) # 22.10.20                #연구소 3
add_executable(backjoon-17779 backjoon/17779-GeryMendering.cc) # 22.10.24                #게리맨더링 2
add_executable(backjoon-17837 backjoon/17837-NewGame2.cc) # 22.10.26                #새로운 게임 2
add_executable(backjoon-17822 backjoon/17822-RotateDisk.cc) # 22.11.10                #원판 돌리기 #(Renew1 23.03.20)
add_executable(backjoon-4179 backjoon/4179-Fire.cc) # 23.01.04                #불 #(Renew1 23.01.09)
add_executable(backjoon-15686V2 backjoon/15686-DeliveryChickenV2.cc) # 23.01.10                #불
add_executable(backjoon-2636 backjoon/2636-Cheese.cc) # 23.01.13                #치즈
add_executable(backjoon-2309 backjoon/2309-SevenDwarf.cc) # 23.01.23                #일곱난쟁이
add_executable(backjoon-10808 backjoon/10808-AlphabatNumber.cc) # 23.01.23                #알파벳 개수
add_executable(backjoon-2979 backjoon/2979-TruckParking.cc) # 23.01.23                #트럭 주차
add_executable(backjoon-10988 backjoon/10988-CheckPellinDrom.cc) # 23.01.23                #팰린드롬인지 확인하기
add_executable(backjoon-1159 backjoon/1159-BascketBallGame.cc) # 23.01.23                #농구 경기
add_executable(backjoon-11655 backjoon/11655-ROT13.cc) # 23.01.23                #ROT13
add_executable(backjoon-9996 backjoon/9996-MissKorea.cc) # 23.01.23                #한국이 그리울 땐 써버에 접속하지
add_executable(backjoon-2559 backjoon/2559-Progression.cc) # 23.01.24                #수열
add_executable(backjoon-1620 backjoon/1620-ImPoketmonMaster.cc) # 23.01.24                #나는야 포켓몬 마스터 이다솜
add_executable(backjoon-9375 backjoon/9375-FashionKingSinHaeBin.cc) # 23.01.26                #패션왕 신해빈
add_executable(backjoon-1213 backjoon/1213-MakePelinDrom.cc) # 23.01.26                #팰린드롬 만들기
add_executable(backjoon-1940 backjoon/1940-JooMong.cc) # 23.01.30                #주몽
add_executable(backjoon-1629 backjoon/1629-Multiply.cc) # 23.01.31                #곱셈
add_executable(backjoon-4375 backjoon/4375-one.cc) # 23.01.31                #1
add_executable(backjoon-1012 backjoon/1012-OrganicCabbage.cc) # 23.02.01                #유기농배추
add_executable(backjoon-1992 backjoon/1992-QuardTree.cc) # 23.02.02                #쿼드트리
add_executable(backjoon-2828 backjoon/2828-TakeAppleInBoxGame.cc) # 23.02.02                #사과 담기 게임
add_executable(backjoon-3986 backjoon/3986-GoodWord.cc) # 23.02.05                #좋은 단어
add_executable(backjoon-2910 backjoon/2910-BindoSort.cc) # 23.02.07                #빈도 정렬
add_executable(backjoon-4659 backjoon/4659-PronouncePassword.cc) # 23.02.07                #비밀번호 발음하기
add_executable(backjoon-2870 backjoon/2870-MathHomework.cc) # 23.02.09                #수학 숙제
add_executable(backjoon-10709 backjoon/10709-WeatherCaster.cc) # 23.02.09                #기상캐스터
add_executable(backjoon-3474 backjoon/3474-ProfessorHyunWoo.cc) # 23.02.10                #교수가 된 현우
add_executable(backjoon-2852 backjoon/2852-NbaBasketBall.cc) # 23.02.10                #NBA 농구
add_executable(backjoon-1436 backjoon/1436-MovieDirector.cc) # 23.02.11                #영화감독 숌
add_executable(backjoon-9012 backjoon/9012-Parenthesis.cc) # 23.02.11                #괄호 #(Renew1 23.02.13)
add_executable(backjoon-4949 backjoon/4949-BalancedWorld.cc) # 23.02.11                #균형잡힌 세상
add_executable(backjoon-1068 backjoon/1068-Tree.cc) # 23.02.11                #트리
add_executable(backjoon-1325 backjoon/1325-EfficientHacking.cc) # 23.02.12                #효율적인 해킹
add_executable(backjoon-17298 backjoon/17298-FiveBigNumber.cc) # 23.02.13                #오큰수 #(Renew1 23.02.13)
add_executable(backjoon-12851 backjoon/12851-HideAndSeek2.cc) # 23.02.16                #숨바꼭질2
add_executable(backjoon-13913 backjoon/13913-HideAndSeek4.cc) # 23.02.16                #숨바꼭질4
add_executable(backjoon-17071 backjoon/17071-HideAndSeek5.cc) # 23.02.17                #숨바꼭질5
add_executable(backjoon-14497 backjoon/14497-JunanNan.cc) # 23.02.17                #주난의 난
add_executable(backjoon-3197 backjoon/3197-LakeOfSwan.cc) # 23.02.19                #백조의 호수
add_executable(backjoon-1987 backjoon/1987-Alphabat.cc) # 23.02.19                #알파벳
add_executable(backjoon-2529 backjoon/2529-InequalitySign.cc) # 23.02.19                #부등호 #(Renew1 23.02.19)
add_executable(backjoon-9934 backjoon/9934-CompletBinaryTree.cc) # 23.02.19                #완전 이진 트리
add_executable(backjoon-14620 backjoon/14620-FlowerRoad.cc) # 23.02.20                #꽃길
add_executable(backjoon-1189 backjoon/1189-ComeBackHome.cc) # 23.02.20                #컴백홈
add_executable(backjoon-19942 backjoon/19942-Diet.cc) # 23.02.21                #다이어트
add_executable(backjoon-1285 backjoon/1285-FlipTheCoin.cc) # 23.02.21                #동전던지기(못풀음)
add_executable(backjoon-17471 backjoon/17471-GaryMendering.cc) # 23.02.22                #게리멘더링
add_executable(backjoon-1062 backjoon/1062-Teach.cc) # 23.02.23                #가르침
add_executable(backjoon-1094 backjoon/1094-Stick.cc) # 23.02.23                #막대기
add_executable(backjoon-11723 backjoon/11723-Set.cc) # 23.02.25                #집합
add_executable(backjoon-14391 backjoon/14391-PieceOfPaper.cc) # 23.02.25                #종이 조각(못풀음)
add_executable(backjoon-13244 backjoon/13244-Tree.cc) # 23.02.25                #Tree
add_executable(backjoon-5430 backjoon/5430-AC.cc) # 23.02.25                #AC
add_executable(backjoon-14405 backjoon/14405-Picachu.cc) # 23.02.28                #피카츄
add_executable(backjoon-15353 backjoon/15353-BigNumberAB.cc) # 23.02.28                #큰수 A+B(2)
add_executable(backjoon-15926 backjoon/15926-HyuenUckParenthesis.cc) # 23.03.01                #현욱은 괄호왕이야!!
add_executable(backjoon-3015 backjoon/3015-UnitedOasis.cc) # 23.03.03                #오아시스 재결합
add_executable(backjoon-2109 backjoon/2109-LectureTour.cc) # 23.03.06                #순회강연(못풀음)
add_executable(backjoon-9935 backjoon/9935-ExplosionCharacter.cc) # 23.03.06                #문자열 폭발
add_executable(backjoon-1781 backjoon/1781-CupNoodle.cc) # 23.03.07                #컵라면
add_executable(backjoon-14469 backjoon/14469-WhyCowCrossTheRoad3.cc) # 23.03.07                #소가 길을 건너간 이유3
add_executable(backjoon-1202 backjoon/1202-JewelThief.cc) # 23.03.07                #보석도둑
add_executable(backjoon-1644 backjoon/1644-SumOfPrimeNumbers.cc) # 23.03.08                #소수의 연속합
add_executable(backjoon-13144 backjoon/13144-ListOfUniqueNumbers.cc) # 23.03.08                #List of Unique Numbers
add_executable(backjoon-3273 backjoon/3273-SumOfTwoNumber.cc) # 23.03.09                #두 수의 합 #Renew1(23.03.09)
add_executable(backjoon-1700 backjoon/1700-MultitabSchedualing.cc) # 23.03.09                #멀티탭 스케줄링 #(Renew1 23.03.09)
add_executable(backjoon-17406 backjoon/17406-RotateArray4.cc) # 23.03.12    #배열 돌리기4
add_executable(backjoon-17825 backjoon/17825-DiceYut.cc) # 23.03.18    #주사위 윳놀이(못품)
add_executable(backjoon-2632 backjoon/2632-SellingPizza.cc) # 23.03.20    #피자판매(못품)
add_executable(backjoon-2170 backjoon/2170-DrawLine.cc) # 23.03.21    #선긋기
add_executable(backjoon-2792 backjoon/2792-JewelCase.cc) # 23.03.23    #보석 상자(못품)
add_executable(backjoon-2343 backjoon/2343-GuitarLesson.cc) # 23.03.23    #기타 레슨