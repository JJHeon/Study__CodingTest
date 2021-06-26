/*
@Title		: 백준
@Name		: 로봇 청소기
@First0		: 20.11.09
@Revision1	: 21.02.07
@ETC		: G5
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_14503__
//1
#if 1
#include <iostream>
using namespace std;

#define DIRTY	0
#define WALL	1
#define CLEAN	2

int N, M;
int MAP[50][50];

int DIR;
int DIR_I[4] = { -1, 0, 1, 0 };
int DIR_Y[4] = { 0, 1, 0, -1 };

int cI, cY;

void RotateDirection() {
	DIR = (DIR + 3) % 4;
}

int main() {
	cin >> N >> M;
	cin >> cI >> cY >> DIR;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];

	int nI;
	int nY;

	while (1) {
	RESET:

		MAP[cI][cY] = CLEAN;

		for (int i = 0; i < 4; i++) {
			RotateDirection();
			nI = cI + DIR_I[DIR];
			nY = cY + DIR_Y[DIR];

			if (MAP[nI][nY] == DIRTY) {
				cI = nI;
				cY = nY;
				goto RESET;
			}
		}

		RotateDirection();
		RotateDirection();

		nI = cI + DIR_I[DIR];
		nY = cY + DIR_Y[DIR];

		if (MAP[nI][nY] == CLEAN) {
			RotateDirection();
			RotateDirection();

			cI = nI;
			cY = nY;
			continue;
		}
		else if (MAP[nI][nY] == WALL) break;

	}

	int RESULT = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == CLEAN) RESULT++;
		}

	cout << RESULT;
}
#endif 

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
int N, M;
int place[51][51];
int direction;
int cleaned_position;
enum enum_WAY {
	north, east, south, west
};
enum enum_STATE {
	dirty, wall, cleaned
};
int way_vertical[4] = { -1,0,1,0 };
int way_horizontal[4] = { 0,1,0,-1 };

using namespace std;

int main() {
	int current_X, current_Y;
	cin >> N >> M;
	cin >> current_X >> current_Y >> direction;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> place[i][j];
		}
	}


	bool is_finish = false;
	while (!is_finish)
	{
		place[current_X][current_Y] = cleaned;
		bool check_rotate = true;
		int temp_direction = direction;
		for (int i = 0; i < 4; i++) {
			temp_direction = (temp_direction + 3) % 4;


			int futher_X = current_X + way_vertical[temp_direction];
			int futher_Y = current_Y + way_horizontal[temp_direction];
			if (futher_X < 0 || futher_X >= N || futher_Y < 0 || futher_Y >= M) continue;

			if (place[futher_X][futher_Y] == 0) {
				current_X = futher_X;
				current_Y = futher_Y;
				direction = temp_direction;

				check_rotate = false;
				break;
			}
		}


		if (check_rotate) {
			int temp_direction = (direction + 2) % 4;

			int futher_X = current_X + way_vertical[temp_direction];
			int futher_Y = current_Y + way_horizontal[temp_direction];
			if (futher_X >= 0 && futher_X < N && futher_Y >= 0 && futher_Y < M) {
				switch (place[futher_X][futher_Y]) {
				case wall:
					is_finish = true;
					break;
				case cleaned:
					current_X = futher_X;
					current_Y = futher_Y;

					break;
				}
			}
		}

		//Debug
		/*cout << current_X << " , " << current_Y << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << place[i][j];
			}
			cout << endl;
		}
		cout << endl << endl;*/
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (place[i][j] == cleaned) result++;
		}
	}
	cout << result;

	return 0;
}
#endif

#endif
