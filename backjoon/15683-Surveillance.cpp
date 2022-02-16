/*
@Title		: 백준
@Name		: 감시
@First0		: 20.12.02
@Revision1	: 21.02.11
@ETC		: G5
항상 Top이 최신 코드
*/

#define	__BACKJOON_15683__	1		//21.02.11	//??

#if __BACKJOON_15683__

//1
/*
코드는 좀 더 간단하고 빠르게 짤 수 있게 됬지만 속도는 더 느려졌다.
아마도 bfs를 반복하는 도중 queue를 써서 그런게 아닐까 싶다.
*/
#if 1
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdint>

using namespace std;

using CCTV_POS = struct CCTV_POS {
	const int type;
	const int i;
	const int j;

	CCTV_POS(int type, int i, int j) :type(type), i(i), j(j) {}
};

int N, M;
int MAP[8][8];
int CMAP[8][8];

int NofC[5] = { 4, 2, 4, 4, 1 };

int DIR_I[4] = { 0, -1, 0, 1 };
int DIR_J[4] = { 1, 0, -1, 0 };

int RESULT = INT32_MAX;
vector<CCTV_POS> CCTV_LIST;
vector<int> V;

void CCTV_1(int(*Target)[8], int I, int J, int dir) {
	queue<pair<int, int>> Q;
	Q.push(make_pair(I, J));
	Target[I][J] = -1;

	while (!Q.empty()) {
		int nI = Q.front().first + DIR_I[dir];
		int nJ = Q.front().second + DIR_J[dir];
		Q.pop();

		if (nI < 0 || nI >= N || nJ < 0 || nJ >= M) continue;
		if (MAP[nI][nJ] != 6) {
			Q.push(make_pair(nI, nJ));
			Target[nI][nJ] = -1;
		}
	}
}




int CalcultateZero(int(&Target)[8][8]) {
	int RES = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (Target[i][j] == 0) RES++;
	return RES;
}


void DFS(int cnt) {
	if (cnt == CCTV_LIST.size()) {
		memcpy(CMAP, MAP, sizeof(MAP));

		for (int i = 0; i < CCTV_LIST.size(); i++) {
			int I = CCTV_LIST[i].i;
			int J = CCTV_LIST[i].j;
			int dir = V[i];

			switch (CCTV_LIST[i].type)
			{
			case 1:
				CCTV_1(CMAP, I, J, dir);
				break;
			case 2:
				CCTV_1(CMAP, I, J, dir);
				CCTV_1(CMAP, I, J, (dir + 2) % 4);
				break;
			case 3:
				CCTV_1(CMAP, I, J, dir);
				CCTV_1(CMAP, I, J, (dir + 3) % 4);
				break;
			case 4:
				CCTV_1(CMAP, I, J, dir);
				CCTV_1(CMAP, I, J, (dir + 1) % 4);
				CCTV_1(CMAP, I, J, (dir + 3) % 4);
				break;
			case 5:
				for (int k = 0; k < 4; k++) CCTV_1(CMAP, I, J, k);
				break;
			}
		}
		RESULT = min(CalcultateZero(CMAP), RESULT);
		return;
	}

	for (int i = 0; i < NofC[CCTV_LIST[cnt].type - 1]; i++) {

		V.push_back(i);
		DFS(cnt + 1);
		V.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] > 0 && MAP[i][j] < 6) CCTV_LIST.push_back(CCTV_POS(MAP[i][j], i, j));
		}

	DFS(0);
	cout << RESULT;
}
#endif

//0
#if 0
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <climits>
typedef struct {
	int cctv_id;
	int x;
	int y;
} _CCTV;

using namespace std;

//Global
int N, M;
int map[8][8];
int minimum = INT_MAX;

//User_Global
_CCTV cctv[8];
int user_limit[8];
int user_count[8];
int cctv_num;
int total_count = 1;

//Function
void Draw_Sector(int(*temp_map)[8], const int N, const int M, const _CCTV& cctv, int way) {
	switch (cctv.cctv_id) {
	case 1: //cctv 1
	{
		switch (way) {
		case 0:

			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}
			break;
		case 1:
			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}
			break;
		case 2:
			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		case 3:
			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		}
	}

	break;
	case 2: //cctv2
	{
		switch (way) {
		case 0:
			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		case 1:
			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		}
	}
	break;
	case 3:
	{
		switch (way) {
		case 0:
			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		case 1:
			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		case 2:
			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		case 3:
			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		}
	}
	break;
	case 4:
	{
		switch (way) {
		case 0:
			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		case 1:
			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		case 2:
			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			break;
		case 3:
			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		}
	}
	break;
	case 5:
	{
		switch (way)
		{
		case 0:
			//east
			for (int i = cctv.y + 1; i < M; i++) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//south
			for (int i = cctv.x + 1; i < N; i++) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			//west
			for (int i = cctv.y - 1; i >= 0; i--) {
				if (temp_map[cctv.x][i] == 6) break;
				if (temp_map[cctv.x][i] == 0) temp_map[cctv.x][i] = 9;
			}

			//north
			for (int i = cctv.x - 1; i >= 0; i--) {
				if (temp_map[i][cctv.y] == 6) break;
				if (temp_map[i][cctv.y] == 0) temp_map[i][cctv.y] = 9;
			}

			break;
		}
	}
	break;
	}
}


int main() {

	//Input
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//Set Variable
	int temp_count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctv[cctv_num].cctv_id = map[i][j];
				cctv[cctv_num].x = i;
				cctv[cctv_num].y = j;


				switch (cctv[cctv_num].cctv_id) {
				case 1:
				case 3:
				case 4:
					user_limit[temp_count++] = 4;
					total_count *= 4;
					break;
				case 2:
					user_limit[temp_count++] = 2;
					total_count *= 2;
					break;
				case 5:
					user_limit[temp_count++] = 1;
					//total_count *= 1;
					break;
				}

				cctv_num++;
			}
		}
	}
	//Set Configuration
	for (int i = 1; i < cctv_num; i++) {
		user_limit[i] = user_limit[i - 1] * user_limit[i];
	}

	int temp_map[8][8];
	//Calculate
	for (int i = 0; i < total_count; i++) {
		//Copy Map
		memcpy(temp_map, map, sizeof(int) * 8 * 8);

		//Set Count
		if (user_limit[0] != 0) user_count[0] = i % user_limit[0];
		for (int j = 1; j < cctv_num; j++) {
			user_count[j] = (i % user_limit[j]) / user_limit[j - 1];
		}

		//Draw Sector
		for (int j = 0; j < cctv_num; j++) {
			Draw_Sector(temp_map, N, M, cctv[j], user_count[j]);
		}

		//Counting 0
		int count_zero = 0;
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < M; j++) {
				if (temp_map[k][j] == 0) count_zero++;
			}
		}

		//debug
		/*cout << endl << endl;
		for (int i = 0; i < cctv_num; i++) {
			cout << user_count[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << temp_map[i][j];
			}
			cout << endl;
		}*/


		minimum = minimum > count_zero ? count_zero : minimum;

	}

	cout << minimum;

	return 0;
}
#endif

#endif
