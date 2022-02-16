/*
@Title		: 백준
@Name		: 큐빙
@First0		: 21.02.23
@Revision1	: 
@ETC		: G1
항상 Top이 최신 코드
*/

#define	__BACKJOON_5373__	1		//21.02.23	//큐빙

#if __BACKJOON_5373__

//0
#if 0
#include <iostream>
#include <string>
#include <vector>
#define SIZE 3
using namespace std;

/*
W : 0
R : 1
G : 2
O : 3
B : 4
Y : 5
*/
int N;
using FnR = struct {
	int F;
	int R;
};


vector<string> COMMAND[1000];

string CUBE[6][3];
string Origin_CUBE[6][3] = { {"www","www","www"},
					 {"rrr","rrr","rrr"},
					 {"ggg","ggg","ggg"},
					 {"ooo","ooo","ooo"},
					 {"bbb","bbb","bbb"},
					 {"yyy","yyy","yyy"} };

const FnR RELATION[6][4] = {
							{{1, 0},{2,0},{3,0},{4,0}},
							{{5, 0},{2,-1},{0,2},{4,1}},
							{{5, 1},{3,-1},{0,1},{1,1}},
							{{5, 2},{4,-1},{0,0},{2,1}},
							{{5, -1},{1,-1},{0,-1},{3,1}},
							{{3, 2},{2,2},{1,2},{4,2}} };

void RotateClock(string(&Target)[SIZE]) {
	string Tmp[SIZE] = { "aaa","aaa","aaa" };
	//for (int i = 0; i < SIZE; i++) Tmp[i] = Target[i];


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Tmp[j][SIZE - 1 - i] = Target[i][j];
		}
	}
	for (int i = 0; i < SIZE; i++) Target[i] = Tmp[i];
}

void RotateCounterClock(string(&Target)[SIZE]) {
	string Tmp[SIZE] = { "aaa","aaa","aaa" };


	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Tmp[SIZE - 1 - j][i] = Target[i][j];
		}
	}
	for (int i = 0; i < SIZE; i++) Target[i] = Tmp[i];
}

void PrintState(string(&Target)[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		cout << Target[i] << endl;
	}
	//cout << endl << endl;
}
void Move(int face, char way) {

	for (int i = 0; i < 4; i++) {
		if (RELATION[face][i].R < 0) for (int j = 0; j != RELATION[face][i].R; j--) RotateCounterClock(CUBE[RELATION[face][i].F]);
		else for (int j = 0; j != RELATION[face][i].R; j++) RotateClock(CUBE[RELATION[face][i].F]);
	}


	string tmp;
	switch (way)
	{
	case '+':
		RotateClock(CUBE[face]);

		tmp = CUBE[RELATION[face][0].F][0];
		CUBE[RELATION[face][0].F][0] = CUBE[RELATION[face][3].F][0];
		CUBE[RELATION[face][3].F][0] = CUBE[RELATION[face][2].F][0];
		CUBE[RELATION[face][2].F][0] = CUBE[RELATION[face][1].F][0];
		CUBE[RELATION[face][1].F][0] = tmp;

		break;
	case '-':
		RotateCounterClock(CUBE[face]);

		tmp = CUBE[RELATION[face][0].F][0];
		CUBE[RELATION[face][0].F][0] = CUBE[RELATION[face][1].F][0];
		CUBE[RELATION[face][1].F][0] = CUBE[RELATION[face][2].F][0];
		CUBE[RELATION[face][2].F][0] = CUBE[RELATION[face][3].F][0];
		CUBE[RELATION[face][3].F][0] = tmp;
		break;
	}

	for (int i = 0; i < 4; i++) {
		if (RELATION[face][i].R < 0) for (int j = RELATION[face][i].R; j != 0; j++) RotateClock(CUBE[RELATION[face][i].F]);
		else for (int j = RELATION[face][i].R; j != 0; j--) RotateCounterClock(CUBE[RELATION[face][i].F]);
	}


}

void Sol(vector<string>(&Target)) {
	for (int i = 0; i < Target.size(); i++) {
		switch (Target[i][0]) {
		case 'U':
			Move(0, Target[i][1]);
			break;
		case 'D':
			Move(5, Target[i][1]);
			break;
		case 'F':
			Move(1, Target[i][1]);
			break;
		case 'B':
			Move(3, Target[i][1]);
			break;
		case 'L':
			Move(2, Target[i][1]);
			break;
		case 'R':
			Move(4, Target[i][1]);
			break;
		}
		//PrintState(CUBE[0]);
	}
	PrintState(CUBE[0]);
}


int main() {
	//Input
	int tmp;
	string tmp_s;
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			cin >> tmp_s;
			COMMAND[i].push_back(tmp_s);
		}
	}


	for (int i = 0; i < N; i++) {
		for (int k = 0; k < 6; k++) for (int l = 0; l < 3; l++) CUBE[k][l] = Origin_CUBE[k][l];
		Sol(COMMAND[i]);
	}

}
#endif
#endif
