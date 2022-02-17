/*
@Title		: 백준
@Name		: 드래곤 커브
@First0		: 21.02.11
@Revision1	: 
@ETC		: G4
항상 Top이 최신 코드
*/

#define	__BACKJOON_15685__	1		//21.02.11	//드래곤 커브

#if __BACKJOON_15685__

//0
#if 1
#include <iostream>
#include <stack>
#include <vector>
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
