/*
@Title		: 백준
@Name		: 테트로미노
@First0		: 20.11.01
@Revision1	: 21.02.03
@Revision2	: 21.02.04
@ETC		: G5
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_14500__

//2
#if 1
#include <iostream>
#include <cstring>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

int N, M;
int MAP[500][500];
bool CHECK[500][500];

int RESULT;
int ROW_DIR[4] = { 0,0,-1,1 };
int COL_DIR[4] = { 1,-1,0,0 };

void ShapeForOdd(int ROW, int COL) {
	if (ROW + 1 < N && COL + 2 < M) RESULT = MAX(RESULT, (MAP[ROW][COL] + MAP[ROW][COL + 1] + MAP[ROW][COL + 2] + MAP[ROW + 1][COL + 1]));
	if (ROW + 2 < N && COL + 1 < M) RESULT = MAX(RESULT, (MAP[ROW][COL] + MAP[ROW + 1][COL] + MAP[ROW + 2][COL] + MAP[ROW + 1][COL + 1]));
	if (ROW - 1 >= 0 && COL + 2 < M) RESULT = MAX(RESULT, (MAP[ROW][COL] + MAP[ROW][COL + 1] + MAP[ROW - 1][COL + 1] + MAP[ROW][COL + 2]));
	if (ROW + 2 < N && COL - 1 >= 0) RESULT = MAX(RESULT, (MAP[ROW][COL] + MAP[ROW + 1][COL] + MAP[ROW + 1][COL - 1] + MAP[ROW + 2][COL]));
}

void DFS(int ROW, int COL, int SUM, int cnt) {
	CHECK[ROW][COL] = true;

	if (cnt == 3) {
		RESULT = MAX(SUM, RESULT);

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nROW = ROW + ROW_DIR[i];
		int nCOL = COL + COL_DIR[i];

		if (nROW < 0 || nROW >= N || nCOL < 0 || nCOL >= M) continue;
		if (CHECK[nROW][nCOL]) continue;

		DFS(nROW, nCOL, SUM + MAP[nROW][nCOL], cnt + 1);


		CHECK[nROW][nCOL] = false;
	}
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(CHECK, false, sizeof(CHECK));
			DFS(i, j, MAP[i][j], 0);
			ShapeForOdd(i, j);
		}
	}
	cout << RESULT;






	return 0;
}
#endif

//1
#if 0
#include <iostream>
#include <cstdint>
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
using namespace std;

typedef struct _Block {
	int row;
	int col;
} _Block;
typedef struct _Set {
	_Block member[4];

} _Set;

//막대
_Set s1[2] = { {0,0 , 0,1 , 0,2 , 0,3 },
			 {0,0 , 1,0 , 2,0 , 3,0} };
//사각형
_Set s2[1] = { {0,0 , 0,1 , 1,0 , 1,1 } };

//니은
_Set s3[8] = { {0,0 , 1,0 , 2,0 , 2,1 },
			   {0,0 , 0,1 , 0,2 , -1,2 },
			   {0,0 , 0,1 , 1,1 , 2,1 },
			   {0,0 , 1,0 , 0,1 , 0,2 },
			   {0,0 , 1,0 , 2,0 , 2,-1 },
			   {0,0 , 1,0 , 1,1 , 1,2 },
			   {0,0 , 0,1 , 1,0 , 2,0 },
			   {0,0 , 0,1 , 0,2 , 1,2 } };

//??
_Set s4[4] = { {0,0 , 1,0 , 1,1 , 2,1 },
			   {0,0 , 0,1 , -1,1 , -1,2 },
			   {0,0 , 1,0 , 1,-1 , 2,-1 },
			   {0,0 , 0,1 , 1,1 , 1,2 } };
//ㅗ
_Set s5[4] = { {0,0 , 0,1 , 0,2 , 1,1 },
			   {0,0 , 1,0 , 2,0 , 1,1 },
			   {0,0 , 0,1 , -1,1 , 0,2 },
			   {0,0 , 1,0 , 1,-1 , 2,0 } };

int N, M;
int MAP[500][500];
int RES = INT32_MIN;

int Simulate(_Set* P) {
	int res = INT32_MIN;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int Ar = i + P->member[0].row;
			int Ac = j + P->member[0].col;

			int Br = i + P->member[1].row;
			int Bc = j + P->member[1].col;

			int Cr = i + P->member[2].row;
			int Cc = j + P->member[2].col;

			int Dr = i + P->member[3].row;
			int Dc = j + P->member[3].col;

			if (Ar < 0 || Ar >= N ||
				Ac < 0 || Ac >= M ||
				Br < 0 || Br >= N ||
				Bc < 0 || Bc >= M ||
				Cr < 0 || Cr >= N ||
				Cc < 0 || Cc >= M ||
				Dr < 0 || Dr >= N ||
				Dc < 0 || Dc >= M)
				continue;

			int tmp = MAP[Ar][Ac] + MAP[Br][Bc] + MAP[Cr][Cc] + MAP[Dr][Dc];
			res = MAX(tmp, res);
		}
	}

	return res;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> MAP[i][j];

	for (int i = 0; i < 2; i++) {
		RES = MAX(Simulate(&s1[i]), RES);
	}
	for (int i = 0; i < 1; i++) {
		RES = MAX(Simulate(&s2[i]), RES);
	}
	for (int i = 0; i < 8; i++) {
		RES = MAX(Simulate(&s3[i]), RES);
	}
	for (int i = 0; i < 4; i++) {
		RES = MAX(Simulate(&s4[i]), RES);
	}
	for (int i = 0; i < 4; i++) {
		RES = MAX(Simulate(&s5[i]), RES);
	}

	cout << RES;

	return 0;
}
#endif
//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <climits>
using namespace std;
typedef struct {
	int x;
	int y;
} Shape_;

int N, M;
int** paper;
int user_max = INT_MIN;

//Stick
const Shape_ tetromino_block1[2][4] = {
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{1,0},{2,0},{3,0}}
};
//Box
const Shape_ tetromino_block2[1][4] = {
	{{0,0},{0,1},{1,0},{1,1}}
};
//L
const Shape_ tetromino_block3[8][4] = {
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{0,1},{0,2},{-1,2}},
	{{0,0},{-1,0},{-2,0},{-2,-1}},
	{{0,0}, {0,-1},{0,-2},{1,-2}},
	{{0,0}, {1,0},{2,0},{2,-1}},
	{{0,0},{0,1},{1,0},{2,0}},
	{{0,0},{0,-1},{0,-2},{-1,-2}},
	{{0,0},{0,1},{0,2},{1,2}}
};
//Z
const Shape_ tetromino_block4[4][4] = {
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,0},{0,1},{-1,1},{-1,2}},
	{{0,0},{1,0},{1,-1},{2,-1}},
	{{0,0},{0,1},{1,1},{1,2}}
};
//ㅗ
const Shape_ tetromino_block5[4][4] = {
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,0},{1,0},{2,0},{1,-1}},
	{{0,0},{-1,0},{-2,0},{-1,1}},
	{{0,0},{0,-1},{0,-2},{-1,-1}}
};
void Check_Boundary_Block1(int target_x, int target_y);
void Check_Boundary_Block2(int target_x, int target_y);
void Check_Boundary_Block3(int target_x, int target_y);
void Check_Boundary_Block4(int target_x, int target_y);
void Check_Boundary_Block5(int target_x, int target_y);


int main() {
	//input
	cin >> N >> M;
	paper = new int* [N];
	for (int i = 0; i < N; i++) {
		paper[i] = new int[M];
		for (int j = 0; j < M; j++)
			cin >> paper[i][j];
	}

	//calculate
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			Check_Boundary_Block1(i, j);
			Check_Boundary_Block2(i, j);
			Check_Boundary_Block3(i, j);
			Check_Boundary_Block4(i, j);
			Check_Boundary_Block5(i, j);

		}
	}

	cout << user_max;


	return 0;
}


void Check_Boundary_Block1(int target_x, int target_y) {

	int sum = 0;
	bool is_finish = true;

	for (int i = 0; i < 2; i++) {
		is_finish = true;
		sum = 0;
		for (int j = 0; j < 4; j++) {
			int x_further = target_x + tetromino_block1[i][j].x;
			int y_further = target_y + tetromino_block1[i][j].y;

			if (x_further < 0 || x_further >= N
				|| y_further < 0 || y_further >= M) {
				is_finish = false;
				break;
			}
			else {
				sum += paper[x_further][y_further];
			}
		}

		if (is_finish) user_max = user_max < sum ? sum : user_max;
	}
}
void Check_Boundary_Block2(int target_x, int target_y) {

	int sum = 0;
	bool is_finish = true;

	for (int i = 0; i < 1; i++) {

		is_finish = true;
		sum = 0;

		for (int j = 0; j < 4; j++) {
			int x_further = target_x + tetromino_block2[i][j].x;
			int y_further = target_y + tetromino_block2[i][j].y;

			if (x_further < 0 || x_further >= N
				|| y_further < 0 || y_further >= M) {
				is_finish = false;
				break;
			}
			else {
				sum += paper[x_further][y_further];
			}
		}

		if (is_finish) user_max = user_max < sum ? sum : user_max;

	}
}
void Check_Boundary_Block3(int target_x, int target_y) {


	int sum = 0;
	bool is_finish = true;

	for (int i = 0; i < 8; i++) {
		is_finish = true;
		sum = 0;

		for (int j = 0; j < 4; j++) {
			int x_further = target_x + tetromino_block3[i][j].x;
			int y_further = target_y + tetromino_block3[i][j].y;

			if (x_further < 0 || x_further >= N
				|| y_further < 0 || y_further >= M) {
				is_finish = false;
				break;
			}
			else {
				sum += paper[x_further][y_further];
			}
		}


		if (is_finish) user_max = user_max < sum ? sum : user_max;
	}
}
void Check_Boundary_Block4(int target_x, int target_y) {

	int sum = 0;
	bool is_finish = true;

	for (int i = 0; i < 4; i++) {
		is_finish = true;
		sum = 0;


		for (int j = 0; j < 4; j++) {
			int x_further = target_x + tetromino_block4[i][j].x;
			int y_further = target_y + tetromino_block4[i][j].y;

			if (x_further < 0 || x_further >= N
				|| y_further < 0 || y_further >= M) {
				is_finish = false;
				break;
			}
			else {
				sum += paper[x_further][y_further];
			}
		}

		if (is_finish) user_max = user_max < sum ? sum : user_max;

	}
}
void Check_Boundary_Block5(int target_x, int target_y) {

	int sum = 0;
	bool is_finish = true;

	for (int i = 0; i < 4; i++) {
		is_finish = true;
		sum = 0;

		for (int j = 0; j < 4; j++) {
			int x_further = target_x + tetromino_block5[i][j].x;
			int y_further = target_y + tetromino_block5[i][j].y;

			if (x_further < 0 || x_further >= N
				|| y_further < 0 || y_further >= M) {
				is_finish = false;
				break;
			}
			else {
				sum += paper[x_further][y_further];
			}
		}

		if (is_finish) user_max = user_max < sum ? sum : user_max;
	}
}
#endif

#endif
