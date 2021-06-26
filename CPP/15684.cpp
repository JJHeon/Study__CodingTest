/*
@Title		: 백준
@Name		: 사다리 조작
@First0		: 20.12.15
@Revision1	: 21.02.11
@ETC		: G5
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_15684__

//1
#if 1
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N, M, H;
int MAP[31][11];

vector<pair<int, int>> Q;

bool Cal() {
	for (int j = 1; j <= H; j++) {
		int last_j = j;
		int begin_j = j;
		for (int i = 1; i <= N; i++) {
			if (MAP[i][last_j]) {
				if (last_j <= H - 1) last_j++;
			}
			else if (MAP[i][last_j - 1]) last_j--;
		}
		if (last_j != begin_j) return false;
	}

	return true;
}

bool DFS(int I, int J, int cnt, int Limit) {

	if (cnt == Limit) {

		if (Cal()) {
			while (!Q.empty()) {
				int i = Q.back().first;
				int j = Q.back().second;

				MAP[i][j] = 0;
				Q.pop_back();
			}

			return true;
		}

		return false;
	}

	for (; I <= N; I++) {
		for (; J <= H - 1; J++) {
			if (MAP[I][J - 1] || MAP[I][J] || MAP[I][J + 1]) continue;

			MAP[I][J] = 2;
			Q.push_back(make_pair(I, J));
			if (DFS(I, J + 1, cnt + 1, Limit)) return true;
			MAP[I][J] = 0;
			Q.pop_back();
		}
		J = 1;
	}

	return false;
}

int main() {
	//Input
	cin >> H >> M >> N;
	for (int k = 0; k < M; k++) {
		int I, J;
		cin >> I >> J;
		MAP[I][J] = 1;
	}
	if (DFS(1, 1, 0, 0)) cout << 0;

	else if (DFS(1, 1, 0, 1)) cout << 1;
	else if (DFS(1, 1, 0, 2)) cout << 2;
	else if (DFS(1, 1, 0, 3)) cout << 3;
	else cout << -1;

	return 0;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
using namespace std;

//Global Variable
int N, M, H;
int** horizen_line;

int user_horizen_line[3][2];
int user_horizen_size;

//Function
bool Module_One();
bool Module_Two();
bool Module_Three();

bool Test();
int Is_It_RorL(int i, int j);
bool Is_It_Cross(int i, int j);

int main() {

	//Input
	cin >> N >> M >> H;

	horizen_line = new int* [M];
	for (int i = 0; i < M; i++) {
		horizen_line[i] = new int[2];
		cin >> horizen_line[i][0] >> horizen_line[i][1];
	}

	int tmp = (N / 2) * H;
	user_horizen_size = 0;
	//Start
	if (M == 0) cout << 0;
	else if (Test()) cout << 0;
	//else if (tmp == M && Test()) cout << 0;
	else if (Module_One()) cout << 1;
	else if (Module_Two()) cout << 2;
	else if (Module_Three()) cout << 3;
	else cout << -1;


	return 0;
}
bool Is_It_Cross(int i, int j) {
	for (int k = 0; k < M; k++) {
		if (horizen_line[k][0] == i && (horizen_line[k][1] == j || horizen_line[k][1] - 1 == j || horizen_line[k][1] + 1 == j)) return true;
	}
	return false;
}

//Right 1, Left -1, false 0
int Is_It_RorL(int i, int j) {
	//if (j - 1 < 1) return false;

	for (int k = 0; k < M; k++) {
		if (horizen_line[k][0] == i && horizen_line[k][1] == (j - 1)) return -1;
		else if (horizen_line[k][0] == i && horizen_line[k][1] == j) return 1;
	}
	for (int k = 0; k < user_horizen_size; k++) {
		if (user_horizen_line[k][0] == i && user_horizen_line[k][1] == (j - 1)) return -1;
		else if (user_horizen_line[k][0] == i && user_horizen_line[k][1] == j) return 1;
	}

	return 0;
}


bool Test() {
	for (int ty = 1; ty <= N; ty++) {

		int y = ty;
		for (int tx = 1; tx <= H; tx++) {

			int tmp = Is_It_RorL(tx, y);
			switch (tmp)
			{
			case -1:
				y--;
				break;
			case 1:
				y++;
				break;
			}

		}
		if (y != ty) return false;
	}
	return true;
}

bool Module_One() {
	user_horizen_size = 1;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {

			if (!Is_It_Cross(i, j)) {
				user_horizen_line[0][0] = i;
				user_horizen_line[0][1] = j;

				if (Test()) {
					/*cout << endl;
					cout << "1 : " << user_horizen_line[0][0] << " " << user_horizen_line[0][1] << endl;

					cout << endl << endl;*/
					return true;
				}

			}
		}
	}
	return false;
}
bool Module_Two() {
	user_horizen_size = 2;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {

			if (!Is_It_Cross(i, j)) {
				user_horizen_line[0][0] = i;
				user_horizen_line[0][1] = j;

				for (int it = i; it <= H; it++) {
					int jt;
					jt = it == i ? (j + 2) : (1);

					for (; jt <= N - 1; jt++) {
						if (!Is_It_Cross(it, jt)) {
							user_horizen_line[1][0] = it;
							user_horizen_line[1][1] = jt;

							if (Test()) {
								/*cout << endl;
								cout << "1 : " << user_horizen_line[0][0] << " " << user_horizen_line[0][1] << endl;
								cout << "2 : " << user_horizen_line[1][0] << " " << user_horizen_line[1][1] << endl;
								cout << endl << endl;*/
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

bool Module_Three() {
	user_horizen_size = 3;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {

			if (!Is_It_Cross(i, j)) {
				user_horizen_line[0][0] = i;
				user_horizen_line[0][1] = j;

				for (int it = i; it <= H; it++) {
					int jt;
					jt = (it == i ? (j + 2) : (1));

					for (; jt <= N - 1; jt++) {
						if (!Is_It_Cross(it, jt)) {
							user_horizen_line[1][0] = it;
							user_horizen_line[1][1] = jt;

							for (int itt = it; itt <= H; itt++) {
								int jtt;
								jtt = (itt == it ? (jt + 2) : (1));

								for (; jtt <= N - 1; jtt++) {
									if (!Is_It_Cross(itt, jtt)) {
										user_horizen_line[2][0] = itt;
										user_horizen_line[2][1] = jtt;

										if (Test()) {
											/*cout << endl;
											cout << "1 : " << user_horizen_line[0][0] << " " << user_horizen_line[0][1] << endl;
											cout << "2 : " << user_horizen_line[1][0] << " " << user_horizen_line[1][1] << endl;
											cout << "3 : " << user_horizen_line[2][0] << " " << user_horizen_line[2][1] << endl;
											cout << endl << endl;*/
											return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
#endif

#endif
