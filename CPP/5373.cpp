/*
@Title		: 백준
@Name		: 큐빙
@First0		: 21.02.23
@Revision1	: 21.02.23
@ETC		: G1
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_5373__
//1
#if 1
#include<iostream>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

int N;
vector<pair<char, char>> V;
vector<char> Cube[7];

void Initialize()
{
    V.clear();
    for (int i = 0; i < 7; i++)
    {
        Cube[i].clear();
    }
}

void Input()
{
    cin >> N;
    string Inp;

    for (int i = 0; i < N; i++)
    {
        cin >> Inp;
        char a = Inp[0];
        char b = Inp[1];

        //cout << a << b << "\n";
        V.push_back(make_pair(a, b));
    }

    for (int i = 0; i < 9; i++)
    {
        Cube[1].push_back('w');    // 위
        Cube[2].push_back('y'); // 아래
        Cube[3].push_back('r'); // 앞
        Cube[4].push_back('o'); // 뒤
        Cube[5].push_back('g'); // 왼
        Cube[6].push_back('b'); // 오
    }
}
// 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

int Select_Phase(char Where)
{
    if (Where == 'U') return 1;
    else if (Where == 'D') return 2;
    else if (Where == 'F') return 3;
    else if (Where == 'B') return 4;
    else if (Where == 'L') return 5;
    else if (Where == 'R') return 6;
}

void ReSetting(char Where, char Dir)
{
    int Phase = Select_Phase(Where);

    if (Dir == '+')
    {
        int Tmp1 = Cube[Phase].at(0);
        Cube[Phase].at(0) = Cube[Phase].at(6);
        Cube[Phase].at(6) = Cube[Phase].at(8);
        Cube[Phase].at(8) = Cube[Phase].at(2);
        Cube[Phase].at(2) = Tmp1;

        int Tmp2 = Cube[Phase].at(1);
        Cube[Phase].at(1) = Cube[Phase].at(3);
        Cube[Phase].at(3) = Cube[Phase].at(7);
        Cube[Phase].at(7) = Cube[Phase].at(5);
        Cube[Phase].at(5) = Tmp2;
    }
    else if (Dir == '-')
    {
        int Tmp1 = Cube[Phase].at(0);
        Cube[Phase].at(0) = Cube[Phase].at(2);
        Cube[Phase].at(2) = Cube[Phase].at(8);
        Cube[Phase].at(8) = Cube[Phase].at(6);
        Cube[Phase].at(6) = Tmp1;

        int Tmp2 = Cube[Phase].at(1);
        Cube[Phase].at(1) = Cube[Phase].at(5);
        Cube[Phase].at(5) = Cube[Phase].at(7);
        Cube[Phase].at(7) = Cube[Phase].at(3);
        Cube[Phase].at(3) = Tmp2;
    }
}

void Change_Cube(char Where, char Dir)
// 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오
{
    if (Where == 'U')
    {
        if (Dir == '+')
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[6].at(0);
            Tmp2 = Cube[6].at(1);
            Tmp3 = Cube[6].at(2);

            Cube[6].at(0) = Cube[4].at(0);
            Cube[6].at(1) = Cube[4].at(1);
            Cube[6].at(2) = Cube[4].at(2);

            Cube[4].at(0) = Cube[5].at(0);
            Cube[4].at(1) = Cube[5].at(1);
            Cube[4].at(2) = Cube[5].at(2);

            Cube[5].at(0) = Cube[3].at(0);
            Cube[5].at(1) = Cube[3].at(1);
            Cube[5].at(2) = Cube[3].at(2);

            Cube[3].at(0) = Tmp1;
            Cube[3].at(1) = Tmp2;
            Cube[3].at(2) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[6].at(0);
            Tmp2 = Cube[6].at(1);
            Tmp3 = Cube[6].at(2);

            Cube[6].at(0) = Cube[3].at(0);
            Cube[6].at(1) = Cube[3].at(1);
            Cube[6].at(2) = Cube[3].at(2);

            Cube[3].at(0) = Cube[5].at(0);
            Cube[3].at(1) = Cube[5].at(1);
            Cube[3].at(2) = Cube[5].at(2);

            Cube[5].at(0) = Cube[4].at(0);
            Cube[5].at(1) = Cube[4].at(1);
            Cube[5].at(2) = Cube[4].at(2);

            Cube[4].at(0) = Tmp1;
            Cube[4].at(1) = Tmp2;
            Cube[4].at(2) = Tmp3;
        }
    }
    else if (Where == 'D')    // 아랫면
    {
        if (Dir == '+')    // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(6);
            Tmp2 = Cube[3].at(7);
            Tmp3 = Cube[3].at(8);

            Cube[3].at(6) = Cube[5].at(6);
            Cube[3].at(7) = Cube[5].at(7);
            Cube[3].at(8) = Cube[5].at(8);

            Cube[5].at(6) = Cube[4].at(6);
            Cube[5].at(7) = Cube[4].at(7);
            Cube[5].at(8) = Cube[4].at(8);

            Cube[4].at(6) = Cube[6].at(6);
            Cube[4].at(7) = Cube[6].at(7);
            Cube[4].at(8) = Cube[6].at(8);

            Cube[6].at(6) = Tmp1;
            Cube[6].at(7) = Tmp2;
            Cube[6].at(8) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(6);
            Tmp2 = Cube[3].at(7);
            Tmp3 = Cube[3].at(8);

            Cube[3].at(6) = Cube[6].at(6);
            Cube[3].at(7) = Cube[6].at(7);
            Cube[3].at(8) = Cube[6].at(8);

            Cube[6].at(6) = Cube[4].at(6);
            Cube[6].at(7) = Cube[4].at(7);
            Cube[6].at(8) = Cube[4].at(8);

            Cube[4].at(6) = Cube[5].at(6);
            Cube[4].at(7) = Cube[5].at(7);
            Cube[4].at(8) = Cube[5].at(8);

            Cube[5].at(6) = Tmp1;
            Cube[5].at(7) = Tmp2;
            Cube[5].at(8) = Tmp3;
        }
    }
    else if (Where == 'F')
    {
        if (Dir == '+')    // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[1].at(6);
            Tmp2 = Cube[1].at(7);
            Tmp3 = Cube[1].at(8);

            Cube[1].at(6) = Cube[5].at(8);
            Cube[1].at(7) = Cube[5].at(5);
            Cube[1].at(8) = Cube[5].at(2);

            Cube[5].at(8) = Cube[2].at(2);
            Cube[5].at(5) = Cube[2].at(1);
            Cube[5].at(2) = Cube[2].at(0);

            Cube[2].at(2) = Cube[6].at(0);
            Cube[2].at(1) = Cube[6].at(3);
            Cube[2].at(0) = Cube[6].at(6);

            Cube[6].at(0) = Tmp1;
            Cube[6].at(3) = Tmp2;
            Cube[6].at(6) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[1].at(6);
            Tmp2 = Cube[1].at(7);
            Tmp3 = Cube[1].at(8);

            Cube[1].at(6) = Cube[6].at(0);
            Cube[1].at(7) = Cube[6].at(3);
            Cube[1].at(8) = Cube[6].at(6);

            Cube[6].at(0) = Cube[2].at(2);
            Cube[6].at(3) = Cube[2].at(1);
            Cube[6].at(6) = Cube[2].at(0);

            Cube[2].at(2) = Cube[5].at(8);
            Cube[2].at(1) = Cube[5].at(5);
            Cube[2].at(0) = Cube[5].at(2);

            Cube[5].at(8) = Tmp1;
            Cube[5].at(5) = Tmp2;
            Cube[5].at(2) = Tmp3;
        }
    }
    else if (Where == 'B') // 뒷면
    {
        if (Dir == '+')    // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[1].at(0);
            Tmp2 = Cube[1].at(1);
            Tmp3 = Cube[1].at(2);

            Cube[1].at(0) = Cube[6].at(2);
            Cube[1].at(1) = Cube[6].at(5);
            Cube[1].at(2) = Cube[6].at(8);

            Cube[6].at(2) = Cube[2].at(8);
            Cube[6].at(5) = Cube[2].at(7);
            Cube[6].at(8) = Cube[2].at(6);

            Cube[2].at(8) = Cube[5].at(6);
            Cube[2].at(7) = Cube[5].at(3);
            Cube[2].at(6) = Cube[5].at(0);

            Cube[5].at(6) = Tmp1;
            Cube[5].at(3) = Tmp2;
            Cube[5].at(0) = Tmp3;
        }
        else
        {
            // 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[1].at(0);
            Tmp2 = Cube[1].at(1);
            Tmp3 = Cube[1].at(2);

            Cube[1].at(0) = Cube[5].at(6);
            Cube[1].at(1) = Cube[5].at(3);
            Cube[1].at(2) = Cube[5].at(0);

            Cube[5].at(6) = Cube[2].at(8);
            Cube[5].at(3) = Cube[2].at(7);
            Cube[5].at(0) = Cube[2].at(6);

            Cube[2].at(8) = Cube[6].at(2);
            Cube[2].at(7) = Cube[6].at(5);
            Cube[2].at(6) = Cube[6].at(8);

            Cube[6].at(2) = Tmp1;
            Cube[6].at(5) = Tmp2;
            Cube[6].at(8) = Tmp3;
        }
    }
    else if (Where == 'L')
    {
        if (Dir == '+')    // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(0);
            Tmp2 = Cube[3].at(3);
            Tmp3 = Cube[3].at(6);

            Cube[3].at(0) = Cube[1].at(0);
            Cube[3].at(3) = Cube[1].at(3);
            Cube[3].at(6) = Cube[1].at(6);

            Cube[1].at(0) = Cube[4].at(8);
            Cube[1].at(3) = Cube[4].at(5);
            Cube[1].at(6) = Cube[4].at(2);

            Cube[4].at(8) = Cube[2].at(0);
            Cube[4].at(5) = Cube[2].at(3);
            Cube[4].at(2) = Cube[2].at(6);

            Cube[2].at(0) = Tmp1;
            Cube[2].at(3) = Tmp2;
            Cube[2].at(6) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(0);
            Tmp2 = Cube[3].at(3);
            Tmp3 = Cube[3].at(6);

            Cube[3].at(0) = Cube[2].at(0);
            Cube[3].at(3) = Cube[2].at(3);
            Cube[3].at(6) = Cube[2].at(6);

            Cube[2].at(0) = Cube[4].at(8);
            Cube[2].at(3) = Cube[4].at(5);
            Cube[2].at(6) = Cube[4].at(2);

            Cube[4].at(8) = Cube[1].at(0);
            Cube[4].at(5) = Cube[1].at(3);
            Cube[4].at(2) = Cube[1].at(6);

            Cube[1].at(0) = Tmp1;
            Cube[1].at(3) = Tmp2;
            Cube[1].at(6) = Tmp3;
        }
    }
    else if (Where == 'R')
    {
        if (Dir == '+')    // 시계방향으로
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(2);
            Tmp2 = Cube[3].at(5);
            Tmp3 = Cube[3].at(8);

            Cube[3].at(2) = Cube[2].at(2);
            Cube[3].at(5) = Cube[2].at(5);
            Cube[3].at(8) = Cube[2].at(8);

            Cube[2].at(2) = Cube[4].at(6);
            Cube[2].at(5) = Cube[4].at(3);
            Cube[2].at(8) = Cube[4].at(0);

            Cube[4].at(6) = Cube[1].at(2);
            Cube[4].at(3) = Cube[1].at(5);
            Cube[4].at(0) = Cube[1].at(8);

            Cube[1].at(2) = Tmp1;
            Cube[1].at(5) = Tmp2;
            Cube[1].at(8) = Tmp3;
        }
        else
        {
            char Tmp1, Tmp2, Tmp3;
            Tmp1 = Cube[3].at(2);
            Tmp2 = Cube[3].at(5);
            Tmp3 = Cube[3].at(8);

            Cube[3].at(2) = Cube[1].at(2);
            Cube[3].at(5) = Cube[1].at(5);
            Cube[3].at(8) = Cube[1].at(8);

            Cube[1].at(2) = Cube[4].at(6);
            Cube[1].at(5) = Cube[4].at(3);
            Cube[1].at(8) = Cube[4].at(0);

            Cube[4].at(6) = Cube[2].at(2);
            Cube[4].at(3) = Cube[2].at(5);
            Cube[4].at(0) = Cube[2].at(8);

            Cube[2].at(2) = Tmp1;
            Cube[2].at(5) = Tmp2;
            Cube[2].at(8) = Tmp3;
        }
    }
    // U D F B L R 
    // U+ U- D- F+ B+ L+ L- R+
    // D+ F- B- R-
    ReSetting(Where, Dir);
    //PrintCubeState();
    //cout << "===========================================" << endl;
    /*cout << "#########################################" << endl;
    int Cnt = 1;
    for (int i = 0; i < 9; i++)
    {
        cout << Cube[1].at(i);
        if (Cnt == 3)
        {
            cout << endl;
            Cnt = 0;
        }
        Cnt++;
    }
    cout << "#########################################" << endl;
*/
}

void Solution()
{
    for (int i = 0; i < V.size(); i++)
    {
        char Where = V[i].first;
        char Dir = V[i].second;
        Change_Cube(Where, Dir);
    }
}

void Solve()
{
    int Tc;
    cin >> Tc;

    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        int Cnt = 1;
        for (int i = 0; i < 9; i++)
        {
            cout << Cube[1].at(i);

            if (Cnt == 3)
            {
                cout << endl;
                Cnt = 0;
            }
            Cnt++;

        }
        // 1 = 위 | 2 = 아래 | 3 = 앞 | 4 = 뒤 | 5 = 왼 | 6 = 오

        //PrintCubeState();


    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //    freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
Colored by Color Scripter
cs


출처 : https://yabmoons.tistory.com/103 [얍문's Coding World..]
#endif

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
