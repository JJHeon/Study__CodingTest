/*
@Title		: 백준
@Name		: 연구소
@First0		: 20.11.08
@Revision1	: 21.02.06
@Revision2	: 21.02.07
@ETC		: G5
항상 Top이 최신 코드
*/

#define	__BACKJOON_14502__	1		//21.02.07	//연구소

#if __BACKJOON_14502__
//2
#if 1
#include <iostream>
#include <cstring>
#include <queue>
#define MAX(A, B) (((A) > (B)) ? (A) : (B))

using namespace std;

typedef struct Point {
	int I;
	int J;
} P;

int N;
int M;
int MAP[8][8];
int CMAP[8][8];
int RESULT;

int DIR_I[4] = { 0, 0, 1, -1 };
int DIR_J[4] = { 1, -1, 0, 0 };
P W[3];

int CountMaximumSaveArea(int(&Target)[8][8]) {
	int RES = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Target[i][j] == 0) RES += 1;
		}
	}

	return RES;
}

// DFS case
/*
* void ActiveVirus(int (&Target)[8][8], int i, int j) {
	Target[i][j] = 2;

	int nI;
	int nJ;
	for (int dir = 0; dir < 4; dir++) {
		nI = i + DIR_I[dir];
		nJ = j + DIR_J[dir];
		if (nI < 0 || nI >= N || nJ < 0 || nJ >= M) continue;
		if (Target[nI][nJ] == 1 || Target[nI][nJ] == 2) continue;

		ActiveVirus(Target, nI, nJ);
	}
}
*/


void BFS(int(&Target)[8][8]) {

	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Target[i][j] == 2) Q.push(make_pair(i, j));
		}
	}

	int nI, nJ;
	int i, j;
	while (!Q.empty()) {
		i = Q.front().first;
		j = Q.front().second;

		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			nI = i + DIR_I[dir];
			nJ = j + DIR_J[dir];
			if (nI < 0 || nI >= N || nJ < 0 || nJ >= M) continue;
			if (CMAP[nI][nJ] == 0) {
				CMAP[nI][nJ] = 2;
				Q.push(make_pair(nI, nJ));
			}
		}
	}
}

void Sol(int i, int j, int cnt) {
	if (cnt == 0) {
		W[0].I = i;
		W[0].J = j;
	}
	else if (cnt == 1) {
		W[1].I = i;
		W[1].J = j;
	}
	else if (cnt == 2) {
		W[2].I = i;
		W[2].J = j;



		memcpy(CMAP, MAP, sizeof(CMAP));

		CMAP[W[0].I][W[0].J] = 1;
		CMAP[W[1].I][W[1].J] = 1;
		CMAP[W[2].I][W[2].J] = 1;

		//DFS case
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (CMAP[i][j] == 2) ActiveVirus(CMAP, i, j);
			}
		}
		*/

		//BFS case
		BFS(CMAP);


		//Debug
		/*
		cout << endl << "===================" << endl;
		cout << W[0].I << " " << W[0].J << endl;
		cout << W[1].I << " " << W[1].J << endl;
		cout << W[2].I << " " << W[2].J << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << CMAP[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		RESULT = MAX(CountMaximumSaveArea(CMAP), RESULT);
		return;
	}

	for (; i < N; i++) {
		for (; j < M - 1; j++) {

			if (MAP[i][j + 1] == 0) Sol(i, j + 1, cnt + 1);
		}
		j = -1;
	}

	return;
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> MAP[i][j];

	Sol(0, -1, -1);

	cout << RESULT;
}
#endif

//1
#if 0
#include <iostream>
#include <cstring>
#define MAX(A, B) (((A) > (B)) ? (A) : (B))

using namespace std;

typedef struct Point {
	int I;
	int J;
} P;

int N;
int M;
int MAP[8][8];
int CMAP[8][8];
int RESULT;

int DIR_I[4] = { 0, 0, 1, -1 };
int DIR_J[4] = { 1, -1, 0, 0 };
P W[3];

int CountMaximumSaveArea(int(&Target)[8][8]) {
	int RES = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Target[i][j] == 0) RES += 1;
		}
	}

	return RES;
}

void ActiveVirus(int(&Target)[8][8], int i, int j) {
	Target[i][j] = 2;

	int nI;
	int nJ;
	for (int dir = 0; dir < 4; dir++) {
		nI = i + DIR_I[dir];
		nJ = j + DIR_J[dir];
		if (nI < 0 || nI >= N || nJ < 0 || nJ >= M) continue;
		if (Target[nI][nJ] == 1 || Target[nI][nJ] == 2) continue;

		ActiveVirus(Target, nI, nJ);
	}
}

void Sol(int i, int j, int cnt) {
	if (cnt == 0) {
		W[0].I = i;
		W[0].J = j;
	}
	else if (cnt == 1) {
		W[1].I = i;
		W[1].J = j;
	}
	else if (cnt == 2) {
		W[2].I = i;
		W[2].J = j;



		memcpy(CMAP, MAP, sizeof(CMAP));

		CMAP[W[0].I][W[0].J] = 1;
		CMAP[W[1].I][W[1].J] = 1;
		CMAP[W[2].I][W[2].J] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (CMAP[i][j] == 2) ActiveVirus(CMAP, i, j);
			}
		}

		RESULT = MAX(CountMaximumSaveArea(CMAP), RESULT);
		return;
	}

	for (; i < N; i++) {
		for (; j < M - 1; j++) {

			if (MAP[i][j + 1] == 0) Sol(i, j + 1, cnt + 1);
		}
		j = -1;
	}

	return;
}



int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> MAP[i][j];

	Sol(0, -1, -1);

	cout << RESULT;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int N, M;
int map[9][9];
int test_map[9][9];
int user_max = INT_MIN;

bool Check_Is_It_empty(int(&wall)[3][2]) {
	for (int i = 0; i < 3; i++) {
		if (map[wall[i][0]][wall[i][1]] != 0) return false;
	}

	return true;
}
void RecursiveMethod(int(&test_map)[9][9], int x, int y) {
	if (test_map[x][y] == 2) {
		if ((x - 1) >= 0) {
			if (test_map[x - 1][y] == 0) {
				test_map[x - 1][y] = 2;
				RecursiveMethod(test_map, x - 1, y);
			}
		}
		if ((x + 1) < N) {
			if (test_map[x + 1][y] == 0) {
				test_map[x + 1][y] = 2;
				RecursiveMethod(test_map, x + 1, y);
			}
		}
		if ((y - 1) >= 0) {
			if (test_map[x][y - 1] == 0) {
				test_map[x][y - 1] = 2;
				RecursiveMethod(test_map, x, y - 1);
			}
		}
		if ((y + 1) < M) {
			if (test_map[x][y + 1] == 0) {
				test_map[x][y + 1] = 2;
				RecursiveMethod(test_map, x, y + 1);
			}
		}
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int order_of_cell = N * M;
	int cut = M;
	int custom_wall[3][2];
	for (int i = 0; i < order_of_cell; i++) {

		custom_wall[0][0] = i / cut;
		custom_wall[0][1] = i % cut;

		for (int j = i + 1; j < order_of_cell; j++) {

			custom_wall[1][0] = j / cut;
			custom_wall[1][1] = j % cut;

			for (int k = j + 1; k < order_of_cell; k++) {

				custom_wall[2][0] = k / cut;
				custom_wall[2][1] = k % cut;

				if (Check_Is_It_empty(custom_wall)) {
					memcpy(test_map, map, sizeof(int) * 9 * 9);

					for (int ii = 0; ii < 3; ii++) {
						test_map[custom_wall[ii][0]][custom_wall[ii][1]] = 1;
					}

					for (int iii = 0; iii < order_of_cell; iii++) {
						int x = iii / cut;
						int y = iii % cut;
						RecursiveMethod(test_map, x, y);



					}

					int sum = 0;
					for (int iiii = 0; iiii < order_of_cell; iiii++) {
						int x = iiii / cut;
						int y = iiii % cut;
						if (test_map[x][y] == 0) sum++;
					}

					user_max = sum > user_max ? sum : user_max;

					//print
					//cout << endl << endl;
					//cout << custom_wall[0][0] << " " << custom_wall[0][1] << endl;
					//cout << custom_wall[1][0] << " " << custom_wall[1][1] << endl;
					//cout << custom_wall[2][0] << " " << custom_wall[2][1] << endl;
					//for (int ia = 0; ia < N; ia++) {
					//	for (int ja = 0; ja < M; ja++) {
					//		cout << test_map[ia][ja] << " ";
					//	}
					//	cout << endl;
					//}
					//cout << endl << endl;
				}
				else {
					continue;
				}

			}
		}
	}

	cout << user_max;
	return 0;
}
#endif

#endif
