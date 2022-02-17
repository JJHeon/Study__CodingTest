/*
@Title		: 백준
@Name		: 인구이동
@First0		: 21.02.27
@Revision1	: 
@ETC		: G5
항상 Top이 최신 코드
*/

#define	__BACKJOON_16234__	1		//21.02.27	//인구이동

#if __BACKJOON_16234__

//0
#if 1
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int N, L, R, RESULT;
int MAP[50][50];
int OMAP[50][50];

bool CHECK[50][50];

int DIR_I[4] = { 0,1,0,-1 };
int DIR_J[4] = { 1,0,-1,0 };


void BFS(int i, int j) {
	queue<pair<int, int>> Q;
	vector<pair<int, int>> V;

	V.push_back(make_pair(i, j));
	Q.push(make_pair(i, j));

	while (!Q.empty()) {

		int I = Q.front().first;
		int J = Q.front().second;
		Q.pop();

		for (int S = 0; S < 4; S++) {
			int nI = I + DIR_I[S];
			int nJ = J + DIR_J[S];

			if (nI < 0 || nI >= N || nJ < 0 || nJ >= N) continue;
			if (CHECK[nI][nJ]) continue;

			int COMP = abs(OMAP[I][J] - OMAP[nI][nJ]);
			if (COMP >= L && COMP <= R) {
				CHECK[nI][nJ] = true;

				pair<int, int> tmp = make_pair(nI, nJ);
				V.push_back(tmp);
				Q.push(tmp);
			}
		}
	}

	int sum = 0;
	for (vector<pair<int, int>>::iterator it = V.begin(); it != V.end(); it++) sum += OMAP[(*it).first][(*it).second];
	int avg = sum / static_cast<int>(V.size());
	for (vector<pair<int, int>>::iterator it = V.begin(); it != V.end(); it++) MAP[(*it).first][(*it).second] = avg;
}

void Sol() {
	bool is_changed = true;
	int COMP = 0;

	while (is_changed) {

		is_changed = false;
		memcpy(MAP, OMAP, sizeof(MAP));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (CHECK[i][j]) continue;

				for (int S = 0; S < 2; S++) {
					int nI = i + DIR_I[S];
					int nJ = j + DIR_J[S];

					if (nI < 0 || nI >= N || nJ < 0 || nJ >= N)continue;

					int COMP = abs(OMAP[i][j] - OMAP[nI][nJ]);
					if (COMP >= L && COMP <= R) {
						is_changed = true;
						CHECK[i][j] = true;
						BFS(i, j);
						break;
					}
				}
			}
		}
		if (is_changed) {
			RESULT++;
			memcpy(OMAP, MAP, sizeof(OMAP));
			memset(CHECK, false, sizeof(CHECK));
		}
	}

}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> OMAP[i][j];

	Sol();

	cout << RESULT;
}
#endif

#endif
