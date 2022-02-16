/*
@Title		: 백준
@Name		: 주사위 굴리기
@First0		: 20.10.31
@Revision1	: 21.02.02
@ETC		: G5
항상 Top이 최신 코드
*/

#define	__BACKJOON_14499__	1		//21.02.02	//주사위 굴리기

#if __BACKJOON_14499__
//1
#if 1
#include <iostream>

using namespace std;

int N, M;
int MAP[20][20];
int ROW, COL;
int NUM_OF_COMMAND;
int COMMAND[1000];

const int DIR_ROW[4] = { 0, 0, -1, 1 };
const int DIR_COL[4] = { 1, -1, 0, 0 };

int DICE[6];

void RolDice(int Dir) {
	switch (Dir)
	{
	case 1:
	{
		int a = DICE[0], b = DICE[2], c = DICE[3], d = DICE[5];
		DICE[2] = a;
		DICE[5] = b;
		DICE[0] = c;
		DICE[3] = d;
		break;
	}
	case 2:
	{
		int a = DICE[0], b = DICE[3], c = DICE[5], d = DICE[2];
		DICE[3] = a;
		DICE[5] = b;
		DICE[2] = c;
		DICE[0] = d;
		break;
	}
	case 3:
	{
		int a = DICE[5], b = DICE[4], c = DICE[0], d = DICE[1];
		DICE[4] = a;
		DICE[0] = b;
		DICE[1] = c;
		DICE[5] = d;
		break;
	}
	case 4:
	{
		int a = DICE[1], b = DICE[0], c = DICE[4], d = DICE[5];
		DICE[0] = a;
		DICE[4] = b;
		DICE[5] = c;
		DICE[1] = d;
		break;
	}
	}
}

int main() {
	cin >> N >> M >> ROW >> COL >> NUM_OF_COMMAND;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < NUM_OF_COMMAND; i++) {
		cin >> COMMAND[i];
	}

	for (int i = 0; i < NUM_OF_COMMAND; i++) {
		int current_command = COMMAND[i] - 1;

		if (COL + DIR_COL[current_command] < 0 || COL + DIR_COL[current_command] >= M
			|| ROW + DIR_ROW[current_command] < 0 || ROW + DIR_ROW[current_command] >= N) continue;


		RolDice(COMMAND[i]);
		COL += DIR_COL[current_command];
		ROW += DIR_ROW[current_command];

		if (MAP[ROW][COL] == 0) MAP[ROW][COL] = DICE[5];
		else {
			DICE[5] = MAP[ROW][COL];
			MAP[ROW][COL] = 0;
		}

		cout << DICE[0] << endl;
	}


	return 0;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

enum {
	EAST = 1,
	WEST = 2,
	NORTH = 3,
	SOUTH = 4
};

int N, M;
int map[20][20];
int x, y;
int K;
int order[1000];

class Dice_ {
private:
	int x, y;
	int dice[4][3];


public:
	explicit Dice_(int x, int y)
		:x(x), y(y) {
		memset(dice, 0, sizeof(int) * 3 * 4);
	}

	bool Is_Dice_Can_Move(int way) {
		switch (way) {
		case EAST:
			if (y + 1 > M - 1) return false;
			else return true;
			break;
		case WEST:
			if (y - 1 < 0) return false;
			else return true;
			break;
		case NORTH:
			if (x - 1 < 0) return false;
			else return true;
			break;
		case SOUTH:
			if (x + 1 > N - 1) return false;
			else return true;
			break;
		}
	}

	void Roll(int way, int(&map)[20][20]) {
		int pick;

		switch (way) {
		case EAST:
			y++;
			pick = dice[1][2];
			for (int i = 2; i > 0; i--)
				dice[1][i] = dice[1][i - 1];

			dice[1][0] = dice[3][1];
			dice[3][1] = pick;

			break;
		case WEST:
			y--;
			pick = dice[1][0];
			for (int i = 0; i < 2; i++)
				dice[1][i] = dice[1][i + 1];
			dice[1][2] = dice[3][1];
			dice[3][1] = pick;

			break;
		case NORTH:
			x--;
			pick = dice[0][1];
			for (int i = 0; i < 3; i++)
				dice[i][1] = dice[i + 1][1];
			dice[3][1] = pick;
			break;
		case SOUTH:
			x++;
			pick = dice[3][1];
			for (int i = 3; i > 0; i--)
				dice[i][1] = dice[i - 1][1];
			dice[0][1] = pick;
			break;
		}

		if (map[x][y]) {
			dice[3][1] = map[x][y];
			map[x][y] = 0;
		}
		else map[x][y] = dice[3][1];
	}
	void ShowTopface() const {
		cout << dice[1][1] << endl;
	}
};

int main() {
	//입력
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < K; i++)
		cin >> order[i];

	//시작
	Dice_ dice = Dice_(x, y);
	for (int i = 0; i < K; i++) {
		if (dice.Is_Dice_Can_Move(order[i])) {
			dice.Roll(order[i], map);
			dice.ShowTopface();
		}
	}

	return 0;
}
#endif

#endif
