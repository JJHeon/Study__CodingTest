/*
@Title		: 백준
@Name		: 드래곤 커브
@First0		: 21.02.11
@Revision1	: 21.02.11
@ETC		: G4
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_15685__

//1
#if 1
#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 100 + 1;



typedef struct

{

	int y, x;

}Dir;



//right, up, left, down

Dir moveDir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };



bool visited[MAX][MAX];



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N;

	cin >> N;



	for (int i = 0; i < N; i++)

	{

		int y, x, d, g;

		cin >> x >> y >> d >> g;



		vector<int> curve;

		//방향 구성

		curve.push_back(d);

		for (int j = 0; j < g; j++)

		{

			vector<int> temp = curve;

			for (int k = temp.size() - 1; k >= 0; k--)

				curve.push_back((temp[k] + 1) % 4);

		}



		visited[y][x] = true;

		for (int j = 0; j < curve.size(); j++)

		{

			y += moveDir[curve[j]].y;

			x += moveDir[curve[j]].x;



			//범위 내에만 표시

			if (0 <= x && x < MAX && 0 <= y && y < MAX)

				visited[y][x] = true;

		}

	}



	int result = 0;

	for (int j = 0; j < MAX - 1; j++)

		for (int k = 0; k < MAX - 1; k++)

			//정사각형

			if (visited[j][k] && visited[j][k + 1] && visited[j + 1][k] && visited[j + 1][k + 1])

				result++;



	cout << result << "\n";

	return 0;

}



출처: https://jaimemin.tistory.com/1163 [꾸준함]
#endif

//0
#if 0
#include <iostream>
#include <stack>
#include <vector>;
#include <cstring>
using namespace std;
using Command = struct _Command {
	int i;
	int j;
	int d;
	int g;
	_Command(int i, int j, int d, int g) :i(i), j(j), d(d), g(g) {}
};

int RESULT;
int N;
int MAP[101][101];
int DIR_I[4] = { 0,-1,0,1 };
int DIR_J[4] = { 1,0,-1,0 };
vector<Command> List;
vector<int> S;

void Debug() {
	cout << endl << "-----" << endl;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----" << endl;
}

int GetSquere() {
	int RES = 0;
	for (int i = 0; i < 101 - 1; i++) {
		for (int j = 0; j < 101 - 1; j++) {
			if (MAP[i][j] && MAP[i][j + 1] && MAP[i + 1][j] && MAP[i + 1][j + 1]) RES++;
		}
	}
	return RES;
}

void Sol(int I, int J, int cnt, int gen) {
	if (cnt == gen + 1) {

		while (!S.empty()) S.pop_back();
		return;
	}


	if (cnt == 0) {
		int nI = I + DIR_I[S[0]];
		int nJ = J + DIR_J[S[0]];
		MAP[I][J] = 1;
		MAP[nI][nJ] = 1;
		Sol(nI, nJ, cnt + 1, gen);
	}
	else {
		MAP[I][J] = 1;

		int BACKUP_MAP[101][101];
		memcpy(BACKUP_MAP, MAP, sizeof(MAP));

		int nI = I;
		int nJ = J;
		int tmpDir;
		//int size = S.size() - 1;
		for (int i = S.size() - 1; i >= 0; i--) {
			tmpDir = (S[i] + 1) % 4;

			nI = nI + DIR_I[tmpDir];
			nJ = nJ + DIR_J[tmpDir];

			if (nI < 0 || nI >= 101 || nJ < 0 || nJ >= 101) {
				memcpy(MAP, BACKUP_MAP, sizeof(MAP));
				while (!S.empty()) S.pop_back();
				return;
			}

			MAP[nI][nJ] = 1;
			S.push_back(tmpDir);
		}
		//Debug();
		Sol(nI, nJ, cnt + 1, gen);
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		List.push_back(_Command(y, x, d, g));
	}

	for (int i = 0; i < List.size(); i++) {
		S.clear();
		S.push_back(List[i].d);
		Sol(List[i].i, List[i].j, 0, List[i].g);
	}
	RESULT = GetSquere();
	cout << RESULT;

	return 0;
}
#endif

#endif
