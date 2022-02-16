/*
@Title		: 백준
@Name		: 구슬탈출2
@First0		: 20.10.29
@Revision1	: 21.01.26
@Revision2	: 21.02.02
@ETC		: G2
항상 Top이 최신 코드
*/

#define	__BACKJOON_13460__	1		//21.02.02	//구슬 탈출2

#if __BACKJOON_13460__

//2
#if 1
#include <iostream>
#include <cstdint>
using namespace std;

struct Pt {
	int y;
	int x;

	Pt() = default;

	void setPt(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int N, M;
char board[10][10];
Pt R;
Pt B;
Pt O;

const int MAX_CNT = 10;
int final_result = INT32_MAX;
const int DIR_Y[4] = { 0,-1,0,1 };
const int DIR_X[4] = { 1,0,-1,0 };

int DFS(int cnt, Pt pR, Pt pB, int dir) {
	if (cnt > MAX_CNT) return INT32_MAX;

	Pt fR = pR;
	Pt fB = pB;


	int result = INT32_MAX;
	if (dir != -1) {
		while (board[pR.y + DIR_Y[dir]][pR.x + DIR_X[dir]] == '.') {
			pR.y += DIR_Y[dir];
			pR.x += DIR_X[dir];

			if (pR.y == O.y && pR.x == O.x) {
				result = cnt;
				break;
			}
		}

		while (board[pB.y + DIR_Y[dir]][pB.x + DIR_X[dir]] == '.') {
			pB.y += DIR_Y[dir];
			pB.x += DIR_X[dir];

			if (pB.y == O.y && pB.x == O.x) {
				return INT32_MAX;
			}
		}

		if (result < INT32_MAX) return result;

		if (pR.y == fR.y && pR.x == fR.x && pB.y == fB.y && pB.x == fB.x) return INT32_MAX;

		if (pR.x == pB.x && pR.y == pB.y) {
			switch (dir)
			{
			case 0:
				if (fR.x > fB.x) pB.x--;
				else pR.x--;
				break;
			case 1:
				if (fR.y > fB.y) pR.y++;
				else pB.y++;
				break;
			case 2:
				if (fR.x > fB.x) pR.x++;
				else pB.x++;
				break;
			case 3:
				if (fR.y > fB.y) pB.y--;
				else pR.y--;
				break;
			}
		}

	}

	int tmp;
	for (int i = 0; i < 4; i++) {
		tmp = DFS(cnt + 1, pR, pB, i);
		result = result > tmp ? tmp : result;
	}

	return result;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			switch (board[i][j])
			{
			case 'R':
				board[i][j] = '.';
				R.setPt(i, j);
				break;
			case 'B':
				board[i][j] = '.';
				B.setPt(i, j);
				break;
			case 'O':
				board[i][j] = '.';
				O.setPt(i, j);
				break;
			}
		}
	}

	final_result = DFS(0, R, B, -1);
	cout << (final_result < 11 ? final_result : -1);


	return 0;
}
#endif

//1
#if 0

#include <iostream>
#include <cstring>
#include <cstdint>
using namespace std;
#define SWAP(x,y,tmp) do{\
	tmp = x;\
	x = y;\
	y = tmp;\
} while(0)

char arr[12][12];
char tmp_arr[12][12];
int N, M;

bool result = false;
bool sub_result = false;
int current_i = -1;
int result_i = INT32_MAX;

int way[4] = { 0,1,2,3 };
int count_tray[10];

void pick_dir(int i);
void print_debug() {
	cout << "debug" << endl;
	for (int i = 0; i < 10; i++) {
		cout << count_tray[i];
	}
	cout << endl;
	for (int i = 1; i <= N; i++) {
		cout << tmp_arr[i] << endl;

	}
	cout << endl;
}

void DFS(int Cnt) {

	if (Cnt == -1) {
		memcpy(tmp_arr, arr, sizeof(arr));
		sub_result = false;
		for (int i = 0; i < 10; i++) {
			pick_dir(count_tray[i]);
			//print_debug();
			if (result) {
				current_i = i + 1;
				result_i = result_i > current_i ? current_i : result_i;
				result = false;
			}
			if (sub_result) {
				return;
			}


		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		count_tray[Cnt] = way[i];
		DFS(Cnt - 1);
	}
}
void right() {
	char char_tmp;
	for (int j = 1; j < N; j++) {
		for (int i = M - 1; i > 1; i--) {
			if (tmp_arr[j][i] == 'R' || tmp_arr[j][i] == 'B') {
				for (int k = i; k < M - 1; k++) {
					if (tmp_arr[j][k + 1] == '.') SWAP(tmp_arr[j][k], tmp_arr[j][k + 1], char_tmp);
					else if (tmp_arr[j][k + 1] == 'O') {
						if (tmp_arr[j][k] == 'R') {
							tmp_arr[j][k] = '.';
							result = true;

						}
						else if (tmp_arr[j][k] == 'B') {
							tmp_arr[j][k] = '.';
							result = false;
							sub_result = true;
							return;
						}
					}
					else if (tmp_arr[j][k + 1] == 'R' || tmp_arr[j][k + 1] == 'B' || tmp_arr[j][k + 1] == '#') {
						break;
					}

				}
			}
		}
	}
}

void left() {
	char char_tmp;
	for (int j = 1; j <= N; j++) {
		for (int i = 2; i < M; i++) {
			if (tmp_arr[j][i] == 'R' || tmp_arr[j][i] == 'B') {
				for (int k = i; k > 2; k--) {
					if (tmp_arr[j][k - 1] == '.') SWAP(tmp_arr[j][k], tmp_arr[j][k - 1], char_tmp);
					else if (tmp_arr[j][k - 1] == 'O') {
						if (tmp_arr[j][k] == 'R') {

							tmp_arr[j][k] = '.';
							result = true;
						}
						else if (tmp_arr[j][k] == 'B') {
							tmp_arr[j][k] = '.';
							result = false;
							sub_result = true;
							return;
						}
					}
					else if (tmp_arr[j][k - 1] == 'R' || tmp_arr[j][k - 1] == 'B' || tmp_arr[j][k - 1] == '#') {
						break;
					}

				}
			}
		}
	}
}
void up() {
	char char_tmp;
	for (int j = 1; j < M; j++) {
		for (int i = 2; i < N; i++) {
			if (tmp_arr[i][j] == 'R' || tmp_arr[i][j] == 'B') {
				for (int k = i; k > 2; k--) {
					if (tmp_arr[k - 1][j] == '.') SWAP(tmp_arr[k][j], tmp_arr[k - 1][j], char_tmp);
					else if (tmp_arr[k - 1][j] == 'O') {
						if (tmp_arr[k][j] == 'R') {
							tmp_arr[k][j] = '.';
							result = true;
						}
						else if (tmp_arr[k][j] == 'B') {
							tmp_arr[k][j] = '.';
							result = false;
							sub_result = true;
							return;
						}
					}
					else if (tmp_arr[k - 1][j] == 'R' || tmp_arr[k - 1][j] == 'B' || tmp_arr[k - 1][j] == '#') {
						break;
					}

				}
			}
		}
	}
}

void down() {
	char char_tmp;
	for (int j = 1; j < M; j++) {
		for (int i = N - 1; i > 1; i--) {
			if (tmp_arr[i][j] == 'R' || tmp_arr[i][j] == 'B') {
				for (int k = i; k < N - 1; k++) {
					if (tmp_arr[k + 1][j] == '.') SWAP(tmp_arr[k][j], tmp_arr[k + 1][j], char_tmp);
					else if (tmp_arr[k + 1][j] == 'O') {
						if (tmp_arr[k][j] == 'R') {
							tmp_arr[k][j] = '.';
							result = true;
						}
						else if (tmp_arr[k][j] == 'B') {
							tmp_arr[k][j] = '.';
							result = false;
							sub_result = true;
							return;
						}
					}
					else if (tmp_arr[k + 1][j] == 'R' || tmp_arr[k + 1][j] == 'B' || tmp_arr[k + 1][j] == '#') {
						break;
					}

				}
			}
		}
	}
}

void pick_dir(int i) {
	switch (i)
	{
	case 0:
		right();
		break;
	case 1:
		up();
		break;
	case 2:
		left();
		break;
	case 3:
		down();
		break;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> &arr[i][1];
	}
	//for (int i = 0; i <= N; i++) {
	//	for (int j = 0; j <= M; j++) {
	//		cout << arr[i][j];
	//	}
	//	cout << endl;
	//	//cout << arr[i] << endl;
	//}

	DFS(9);
	if (result_i > 10) {
		cout << -1;
	}
	else cout << result_i;

}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#define NUMBER_OF_CASES (1048576)
#define SWAP(A,B,C) (((C)=(A)), ((A)=(B)), ((B)=(C)))
enum {
	LEFT, UP, RIGHT, DOWN
};
enum STATE {
	OVER, FINISH, KEEPGOING
};

using namespace std;
char origin_board[10][11];
char board[10][11];
int p_count;
int N, M;
int cases_record[11];
int cases_count;
int user_min;



enum STATE SelectWaving(int way) {
	/*int pos_red[2];
	int pos_blue[2];

	bool is_red_found = false;
	bool is_blue_found = false;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 2; j++) {
			switch (board[i][j]) {
			case 'R':
				pos_red[0] = i;
				pos_red[1] = j;
				is_red_found = true;
				break;
			case 'B':
				pos_blue[0] = i;
				pos_blue[1] = j;
				is_blue_found = true;
				break;
			default:
				break;
			}
			if (is_red_found && is_blue_found) {
				goto ESCAPE:
			}
		}
	}
ESCAPE:*/
//OVER, EARLY_FINISH, KEEPGOING

	bool is_red_entered = false;
	bool is_blue_entered = false;
	char temp;
	switch (way) {
	case LEFT:
		for (int i = 1; i <= N - 1; i++) {
			for (int j = M - 2; j >= 1; j--) {
				if (board[i][j] == 'R') {
					for (int k = j; k <= M - 2; k++) {
						if ((k + 1) < 0) continue;

						if (board[i][k + 1] == 'O') {
							is_red_entered = true;
							board[i][k] = '.';
						}
						//else if (board[i][k + 1] != '#' && board[i][k+1] != 'B') {
						else if (board[i][k + 1] == '.') {
							SWAP(board[i][k], board[i][k + 1], temp);
						}
						else {
							break;
						}

					}
				}
				else if (board[i][j] == 'B') {
					for (int k = j; k <= M - 2; k++) {
						if ((k + 1) < 0) continue;

						if (board[i][k + 1] == 'O') {
							is_blue_entered = true;
							board[i][k] = '.';
							return OVER;
						}
						//else if (board[i][k + 1] != '#' && board[i][k + 1] != 'R') {
						else if (board[i][k + 1] == '.') {
							SWAP(board[i][k], board[i][k + 1], temp);
						}
						else {
							break;
						}

					}
				}
			}
			if (is_blue_entered && is_red_entered) return OVER;
			else if (is_red_entered) return FINISH;
		}
		break;
	case UP:
		for (int i = 1; i <= M - 2; i++) {
			for (int j = N - 1; j >= 1; j--) {
				if (board[j][i] == 'R') {
					for (int k = j; k <= N - 1; k++) {
						if ((k + 1) < 0) continue;

						if (board[k + 1][i] == 'O') {
							is_red_entered = true;
							board[k][i] = '.';


						}
						//else if (board[k+1][i] != '#' && board[k+1][i] != 'B') {
						else if (board[k + 1][i] == '.') {
							SWAP(board[k + 1][i], board[k][i], temp);
						}
						else {
							break;
						}

					}
				}
				else if (board[j][i] == 'B') {
					for (int k = j; k <= N - 1; k++) {
						if ((k + 1) < 0) continue;

						if (board[k + 1][i] == 'O') {
							is_blue_entered = true;
							board[k][i] = '.';
							return OVER;
						}
						//else if (board[k + 1][i] != '#' && board[k + 1][i] != 'R') {
						else if (board[k + 1][i] == '.') {
							SWAP(board[k + 1][i], board[k][i], temp);
						}
						else {
							break;
						}

					}
				}
			}
			if (is_blue_entered && is_red_entered) return OVER;
			else if (is_red_entered) return FINISH;
		}
		break;
	case RIGHT:
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= M - 2; j++) {
				if (board[i][j] == 'R') {
					for (int k = j; k >= 1; k--) {
						if ((k - 1) < 0) continue;

						if (board[i][k - 1] == 'O') {
							is_red_entered = true;
							board[i][k] = '.';
						}
						//else if (board[i][k - 1] != '#' && board[i][k - 1] != 'B') {
						else if (board[i][k - 1] == '.') {
							SWAP(board[i][k], board[i][k - 1], temp);
						}
						else {
							break;
						}

					}
				}
				else if (board[i][j] == 'B') {
					for (int k = j; k >= 1; k--) {
						if ((k - 1) < 0) continue;

						if (board[i][k - 1] == 'O') {
							is_blue_entered = true;
							board[i][k] = '.';
							return OVER;
						}
						//else if (board[i][k - 1] != '#' && board[i][k - 1] != 'R') {
						else if (board[i][k - 1] == '.') {
							SWAP(board[i][k], board[i][k - 1], temp);
						}
						else {
							break;
						}
					}
				}
			}
			if (is_blue_entered && is_red_entered) return OVER;
			else if (is_red_entered) return FINISH;
		}
		break;
	case DOWN:
		for (int i = 1; i <= M - 2; i++) {
			for (int j = 1; j <= N - 1; j++) {
				if (board[j][i] == 'R') {
					for (int k = j; k >= 1; k--) {
						if ((k - 1) < 0) continue;

						if (board[k - 1][i] == 'O') {
							is_red_entered = true;
							board[k][i] = '.';


						}
						//else if (board[k - 1][i] != '#' && board[k - 1][i] != 'B') {
						else if (board[k - 1][i] == '.') {
							SWAP(board[k - 1][i], board[k][i], temp);
						}
						else {
							break;
						}
					}
				}
				else if (board[j][i] == 'B') {
					for (int k = j; k >= 1; k--) {
						if ((k - 1) < 0) continue;

						if (board[k - 1][i] == 'O') {
							is_blue_entered = true;
							board[k][i] = '.';
							return OVER;
						}
						//else if (board[k - 1][i] != '#' && board[k - 1][i] != 'R') {
						else if (board[k - 1][i] == '.') {
							SWAP(board[k - 1][i], board[k][i], temp);
						}
						else {
							break;
						}
					}
				}
			}
			if (is_blue_entered && is_red_entered) return OVER;
			else if (is_red_entered) return FINISH;
		}
		break;
	}

	return KEEPGOING;
}

void PrintBoard__ForDebug() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << board[i] << endl;
	}
	cout << endl << endl;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i != N; i++) {
		scanf("%s", &origin_board[i]);
	}

	bool check_over_continue = true;
	user_min = NUMBER_OF_CASES; //그냥 큰값 넣어둔 것

	//Brute force Algorithm
	for (p_count = 0; p_count < NUMBER_OF_CASES; p_count++) {
		cases_record[0] = p_count % 4;
		cases_record[1] = (p_count % 16) / 4;
		cases_record[2] = (p_count % 64) / 16;
		cases_record[3] = (p_count % 256) / 64;
		cases_record[4] = (p_count % 1024) / 256;
		cases_record[5] = (p_count % 4096) / 1024;
		cases_record[6] = (p_count % 16384) / 4096;
		cases_record[7] = (p_count % 65536) / 16384;
		cases_record[8] = (p_count % 262144) / 65536;
		cases_record[9] = (p_count % 1048576) / 262144;
		cases_record[10] = LEFT;

		memcpy(board, origin_board, sizeof(char) * 10 * 11);
		cases_count = 0;

		for (int i = 0; i != 11; i++) {
			enum STATE State = SelectWaving(cases_record[i]);
			cases_count++;

			if (State == OVER) {
				cases_count = NUMBER_OF_CASES;
				break;
			}
			else if (State == FINISH) {
				check_over_continue = false;
				goto ESCAPE_FOR_COMPARE_CASE;
			}
			else { //KEEPGOING
			}
			//Debug print
			/*cout << "==========" << endl;
			cout <<"count : "<< p_count <<"| i : "<< i <<"| Dirc : " << cases_record[i];
			PrintBoard__ForDebug();*/
		}

	ESCAPE_FOR_COMPARE_CASE:
		if (cases_count < user_min) user_min = cases_count;

	}
	if (user_min > 10) cout << -1; //Fail
	else if (check_over_continue) cout << -1; //Fail
	else cout << user_min;
	return 0;
}
#endif

#endif
