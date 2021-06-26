/*
@Title		: 백준
@Name		: 경사로
@First0		: 20.11.18
@Revision1	: 21.02.09
@Revision2	: 21.02.09
@ETC		: G3
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_14890__
//2 - 참고
#if 1
#include <cstdio>
int main() {
	int n, l, ans = 0, i, j, c;
	short a[200][100];
	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%hd", &a[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i + n][j] = a[j][i];
	for (i = 0; i < n * 2; i++) {
		c = 1;
		for (j = 0; j < n - 1; j++) {
			if (a[i][j] == a[i][j + 1]) c++;
			else if (a[i][j] + 1 == a[i][j + 1] && c >= l) c = 1;
			else if (a[i][j] - 1 == a[i][j + 1] && c >= 0) c = -l + 1;
			else break;
		}
		if (j == n - 1 && c >= 0) ans++;
	}
	printf("%d", ans);
	return 0;
}
#endif

//1 - 더 안좋아진 버전
#if 0
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N;
int L;
int MAP[100][100];
bool CHECK_H[100][100];
bool CHECK_V[100][100];

int RESULT_H;
int RESULT_V;

void H_Sol() {
	bool criterion = true;
	//std::queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		criterion = true;
		for (int j = 0; j < N - 1; j++) {


			int cI = i;
			int cJ = j;
			int nI = i;
			int nJ = j + 1;



			if (abs(MAP[cI][cJ] - MAP[nI][nJ]) > 1) {
				criterion = false;
				goto Finish;
			}
			else if (MAP[cI][cJ] == MAP[nI][nJ] - 1) {
				if (cJ + 1 - L < 0) {
					criterion = false;
					goto Finish;
				}


				for (int k = cJ; k > cJ - L; k--) {
					if (CHECK_H[cI][k]) {
						criterion = false;
						goto Finish;
					}
					else if (MAP[cI][k] != MAP[cI][cJ]) {
						criterion = false;
						goto Finish;
					}
				}

				for (int k = cJ; k > cJ - L; k--) CHECK_H[cI][k] = true;


			}
			else if (MAP[cI][cJ] == MAP[nI][nJ] + 1) {
				if (nJ + L - 1 >= N) {
					criterion = false;
					goto Finish;
				}

				for (int k = nJ; k < nJ + L; k++) {
					if (CHECK_H[nI][k]) {
						criterion = false;
						goto Finish;
					}
					else if (MAP[nI][k] != MAP[nI][nJ]) {
						criterion = false;
						goto Finish;
					}
				}
				for (int k = nJ; k < nJ + L; k++) CHECK_H[nI][k] = true;

			}

		}
	Finish:
		if (criterion) RESULT_H++;

	}
}

void V_Sol() {
	bool criterion = true;
	std::queue<pair<int, int>> Q;
	for (int i = 0; i < N; i++) {
		criterion = true;
		for (int j = 0; j < N - 1; j++) {


			int cI = j;
			int cJ = i;
			int nI = j + 1;
			int nJ = i;



			if (abs(MAP[cI][cJ] - MAP[nI][nJ]) > 1) {
				criterion = false;
				goto Finish;
			}
			else if (MAP[cI][cJ] == MAP[nI][nJ] - 1) {
				if (cI + 1 - L < 0) {
					criterion = false;
					goto Finish;
				}


				for (int k = cI; k > cI - L; k--) {
					if (CHECK_V[k][cJ]) {
						criterion = false;
						goto Finish;
					}
					else if (MAP[k][cJ] != MAP[cI][cJ]) {
						criterion = false;
						goto Finish;
					}
				}

				for (int k = cI; k > cI - L; k--) CHECK_V[k][cJ] = true;

			}
			else if (MAP[cI][cJ] == MAP[nI][nJ] + 1) {
				if (nI + L - 1 >= N) {
					criterion = false;
					goto Finish;
				}

				for (int k = nI; k < nI + L; k++) {
					if (CHECK_V[k][nJ]) {
						criterion = false;
						goto Finish;
					}
					else if (MAP[k][nJ] != MAP[nI][nJ]) {
						criterion = false;
						goto Finish;
					}
				}
				for (int k = nI; k < nI + L; k++) CHECK_V[k][nJ] = true;

			}

		}
	Finish:
		if (criterion) RESULT_V++;

	}
}


int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];

	H_Sol();
	V_Sol();

	//cout << RESULT_H << endl;
	//cout << RESULT_V << endl;
	cout << RESULT_H + RESULT_V;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int N;
int L;
int arr[100][100];
int result;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	//Horizen
	for (int i = 0; i < N; i++) {

		int same_block_count = 1;

		bool is_changed = false;
		bool is_fail = false;
		for (int j = 0; j < N - 1; j++) {

			if (arr[i][j] == arr[i][j + 1]) {
				same_block_count++;
			}
			//1 Up case
			else if (arr[i][j] + 1 == arr[i][j + 1]) {
				//Fail
				if (is_changed) {
					is_fail = true;
					break;
				}

				//Fine
				if (L <= same_block_count) {
					same_block_count = 1;
					continue;
				}
				//Fail
				else {
					is_fail = true;
					break;
				}
			}
			//1 Down case
			else if (arr[i][j] == arr[i][j + 1] + 1) {
				if (is_changed) {
					is_fail = true;
					break;
				}

				same_block_count = 1;
				is_changed = true;
			}
			//Fail
			else {
				is_fail = true;
				break;
			}

			if (is_changed && same_block_count == L) {
				is_changed = false;
				same_block_count = 0;
			}
		}

		if (!is_fail && !is_changed) result += 1;

	}

	//Vertical
	for (int j = 0; j < N; j++) {

		int same_block_count = 1;

		bool is_changed = false;
		bool is_fail = false;
		for (int i = 0; i < N - 1; i++) {

			if (arr[i][j] == arr[i + 1][j]) {
				same_block_count++;
			}
			//1 Up case
			else if (arr[i][j] + 1 == arr[i + 1][j]) {
				//Fail
				if (is_changed) {
					is_fail = true;
					break;
				}

				//Fine
				if (L <= same_block_count) {
					same_block_count = 1;
					continue;
				}
				//Fail
				else {
					is_fail = true;
					break;
				}
			}
			//1 Down case
			else if (arr[i][j] == arr[i + 1][j] + 1) {
				if (is_changed) {
					is_fail = true;
					break;
				}

				same_block_count = 1;
				is_changed = true;
			}
			//Fail
			else {
				is_fail = true;
				break;
			}

			if (is_changed && same_block_count == L) {
				is_changed = false;
				same_block_count = 0;
			}
		}

		if (!is_fail && !is_changed) result += 1;


	}

	cout << result;
	return 0;
}
#endif

#endif
