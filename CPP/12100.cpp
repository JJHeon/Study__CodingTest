/*
@Title		: 백준
@Name		: 2048(Easy)
@First0		: 20.10.23
@Revision1	: 21.01.07
@ETC		: G2
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_12100__
//#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

using namespace std;

int N;
int result;
int map[22][22];
int tmp_map[22][22];

void choice_right() {

	for (int col = 1; col <= N; col++) {
		int pos = N;
		bool not_rp = false;
		for (int search_end = N; search_end > 0; search_end--) {

			if (tmp_map[col][search_end] != 0) {
				if (!not_rp && pos + 1 <= N && tmp_map[col][search_end] == tmp_map[col][pos + 1]) {
					tmp_map[col][search_end] = 0;
					tmp_map[col][pos + 1] *= 2;
					not_rp = true;
				}
				else {
					int tmp = tmp_map[col][search_end];
					tmp_map[col][search_end] = 0;
					tmp_map[col][pos] = tmp;
					not_rp = false;
					pos--;
				}
			}

		}
	}
}
void choice_up() {
	for (int row = 1; row <= N; row++) {
		int pos = 1;
		bool not_rp = false;
		for (int search_end = 1; search_end <= N; search_end++) {

			if (tmp_map[search_end][row] != 0) {
				if (!not_rp && pos - 1 > 0 && tmp_map[search_end][row] == tmp_map[pos - 1][row]) {
					tmp_map[search_end][row] = 0;
					tmp_map[pos - 1][row] *= 2;
					not_rp = true;
				}
				else {
					int tmp = tmp_map[search_end][row];
					tmp_map[search_end][row] = 0;
					tmp_map[pos][row] = tmp;

					not_rp = false;
					pos++;
				}
			}

		}
	}

}
void choice_left() {
	for (int col = 1; col <= N; col++) {
		int pos = 1;
		bool not_rp = false;
		for (int search_end = 1; search_end <= N; search_end++) {

			if (tmp_map[col][search_end] != 0) {
				if (!not_rp && pos - 1 > 0 && tmp_map[col][search_end] == tmp_map[col][pos - 1]) {
					tmp_map[col][search_end] = 0;
					tmp_map[col][pos - 1] *= 2;
					not_rp = true;
				}
				else {
					int tmp = tmp_map[col][search_end];
					tmp_map[col][search_end] = 0;
					tmp_map[col][pos] = tmp;

					not_rp = false;
					pos++;
				}
			}

		}
	}
}
void choice_down() {
	for (int row = 1; row <= N; row++) {
		int pos = N;
		bool not_rp = false;
		for (int search_end = N; search_end > 0; search_end--) {

			if (tmp_map[search_end][row] != 0) {
				if (!not_rp && pos + 1 <= N && tmp_map[search_end][row] == tmp_map[pos + 1][row]) {
					tmp_map[search_end][row] = 0;
					tmp_map[pos + 1][row] *= 2;
					not_rp = true;
				}
				else {
					int tmp = tmp_map[search_end][row];
					tmp_map[search_end][row] = 0;
					tmp_map[pos][row] = tmp;

					not_rp = false;
					pos--;
				}
			}

		}
	}
}

void choice(int i) {
	switch (i)
	{
	case 0:
		choice_right();
		break;
	case 1:
		choice_up();
		break;
	case 2:
		choice_left();
		break;
	case 3:
		choice_down();
		break;
	}
}



int main(int argc, char** argv) {
	//input
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	for (int i1 = 0; i1 < 4; i1++) {
		for (int i2 = 0; i2 < 4; i2++) {
			for (int i3 = 0; i3 < 4; i3++) {
				for (int i4 = 0; i4 < 4; i4++) {
					for (int i5 = 0; i5 < 4; i5++) {
						memcpy(tmp_map, map, sizeof(int) * 22 * 22);

						choice(i1);
						choice(i2);
						choice(i3);
						choice(i4);
						choice(i5);

						int tmp_result = 0;
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								tmp_result = tmp_map[i][j] > tmp_result ? tmp_map[i][j] : tmp_result;
							}
						}
						result = tmp_result > result ? tmp_result : result;

						////debug
						//cout << endl;
						//for (int i = 1; i <= N; i++) {
						//	for (int j = 1; j <= N; j++) {
						//		cout << tmp_map[i][j] << " ";
						//	}
						//	cout << endl;
						//}
						//cout << endl;
					}
				}
			}
		}
	}
	cout << result;
}


//0 - First
#if 0
#include <iostream>
#include <cstring>
using namespace std;

enum {
	RIGHT, UP, LEFT, DOWN
};

int origin_board[22][22];
int board[22][22];
int cnt;
int N;

void directionSelector(int way) {

	int countMovingBlock = 0;
	bool isRepeated = false;
	switch (way)
	{
	case RIGHT:

		for (int i = 1; i <= N; i++) {
			countMovingBlock = 0;
			isRepeated = false;
			for (int j = N; j >= 1; j--) {
				if (board[i][j] != 0) {
					if ((board[i][j] == board[i][N + 1 - countMovingBlock]) && !isRepeated) {
						board[i][N - countMovingBlock + 1] *= 2;
						board[i][j] = 0;
						isRepeated = true;
					}
					else {
						board[i][N - countMovingBlock] = board[i][j];
						if ((N - countMovingBlock) != j)board[i][j] = 0;
						countMovingBlock++;
						isRepeated = false;
					}
				}
			}
		}
		break;
	case UP:
		for (int i = 1; i <= N; i++) {
			countMovingBlock = 0;
			isRepeated = false;
			for (int j = 1; j <= N; j++) {
				if (board[j][i] != 0) {
					if ((board[j][i] == board[countMovingBlock][i]) && !isRepeated) {
						board[countMovingBlock][i] *= 2;
						board[j][i] = 0;
						isRepeated = true;
					}
					else {
						board[1 + countMovingBlock][i] = board[j][i];
						if ((1 + countMovingBlock) != j)board[j][i] = 0;
						countMovingBlock++;
						isRepeated = false;
					}
				}
			}
		}

		break;
	case LEFT:
		for (int i = 1; i <= N; i++) {
			countMovingBlock = 0;
			isRepeated = false;
			for (int j = 1; j <= N; j++) {
				if (board[i][j] != 0) {
					if ((board[i][j] == board[i][countMovingBlock]) && !isRepeated) {
						board[i][countMovingBlock] *= 2;
						board[i][j] = 0;
						isRepeated = true;
					}
					else {
						board[i][1 + countMovingBlock] = board[i][j];
						if ((1 + countMovingBlock) != j)board[i][j] = 0;
						countMovingBlock++;
						isRepeated = false;
					}
				}
			}
		}

		break;
	case DOWN:
		for (int i = 1; i <= N; i++) {
			countMovingBlock = 0;
			isRepeated = false;
			for (int j = N; j >= 1; j--) {
				if (board[j][i] != 0) {
					if ((board[j][i] == board[N + 1 - countMovingBlock][i]) && !isRepeated) {
						board[N + 1 - countMovingBlock][i] *= 2;
						board[j][i] = 0;
						isRepeated = true;
					}
					else {
						board[N - countMovingBlock][i] = board[j][i];
						if ((N - countMovingBlock) != j)board[j][i] = 0;
						countMovingBlock++;
						isRepeated = false;
					}
				}
			}
		}
		break;
	default:
		break;
	}

}
void printBoard() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "====================" << endl;
}

int main(void) {
	//N 입력
	cin >> N;

	//블록을 입력 받음
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> origin_board[i][j];
		}
	}
	int repeat_count[5];
	int repeat_saver[5];
	int max = 0;
	//cout << endl << endl;
	for (cnt = 0; cnt < 1024; cnt++) {

		memcpy(board, origin_board, sizeof(int) * 22 * 22);

		repeat_count[0] = cnt % 4;
		repeat_count[1] = (cnt % 16) / 4;
		repeat_count[2] = (cnt % 64) / 16;
		repeat_count[3] = (cnt % 256) / 64;
		repeat_count[4] = cnt / 256;

		for (int i = 0; i != 5; i++) {
			directionSelector(repeat_count[i]);
			//cout << i + 1 << " : " << repeat_count[i] << endl << "---------------" << endl;
			//printBoard();
		}


		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] > max) {
					max = board[i][j];
					memcpy(repeat_saver, repeat_count, sizeof(int) * 5);
				}
			}

		}
		//cout << endl << endl << "max : " << max << endl << endl;;
	}
	cout << max;

	return 0;
}
#endif

#endif
