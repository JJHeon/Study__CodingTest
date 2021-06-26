/*
@Title		: 백준
@Name		: 치킨 배달
@First0		: 21.02.11
@Revision1	: 21.02.11
@ETC		:
항상 Top이 최신 코드
*/

#include "Manager.h"

#if __BACKJOON_15686__

//1
/*
* 출처: https://jaimemin.tistory.com/1059 [꾸준함]
*/
#if 1
#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 50;

const int INF = 987654321;



int N, M;

int result;

int graph[MAX][MAX];

vector<pair<int, int>> house, chicken;

bool visited[13];



//맨해튼 거리

int distance(pair<int, int> a, pair<int, int> b)

{

    return abs(a.first - b.first) + abs(a.second - b.second);

}



void DFS(int idx, int selected)

{

    //조건 만족

    if (selected == M)

    {

        int tempResult = 0;

        for (int i = 0; i < house.size(); i++)

        {

            int dist = INF;

            for (int j = 0; j < chicken.size(); j++)

                if (visited[j])

                    dist = min(dist, distance(house[i], chicken[j]));



            tempResult += dist;

        }

        result = min(result, tempResult);

        return;

    }



    //기저 사례

    if (idx == chicken.size())

        return;



    //프랜차이즈 선정

    visited[idx] = true;

    DFS(idx + 1, selected + 1);

    //프랜차이즈 선정 X

    visited[idx] = false;

    DFS(idx + 1, selected);

}



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> N >> M;



    for (int i = 0; i < N; i++)

        for (int j = 0; j < N; j++)

        {

            cin >> graph[i][j];

            if (graph[i][j] == 1)

                house.push_back({ i, j });

            else if (graph[i][j] == 2)

                chicken.push_back({ i, j });

        }



    result = INF;

    DFS(0, 0);

    cout << result << "\n";

    return 0;

}




#endif

//0
#if 0
#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int MAP[51][51];
int RESULT = INT32_MAX;
vector<pair<int, int>> List_C;
vector<pair<int, int>> List_H;
vector<int> V;

void Sol(int K, int cnt) {
	if (cnt == M) {

		int distence = 0;
		for (vector<pair<int, int>>::iterator Kx = List_H.begin(); Kx != List_H.end(); Kx++) {
			int I_H = (*Kx).first;
			int J_H = (*Kx).second;
			int distence_h = INT32_MAX;

			for (const auto& Elem : V) {
				int I_C = List_C[Elem].first;
				int J_C = List_C[Elem].second;
				distence_h = min(distence_h, abs(I_H - I_C) + abs(J_H - J_C));
			}
			distence += distence_h;
		}

		RESULT = min(RESULT, distence);
		return;
	}
	for (; K < List_C.size(); K++) {

		V.push_back(K);
		Sol(K + 1, cnt + 1);
		V.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
		int tmp;
		cin >> tmp;
		switch (tmp)
		{
		case 1:
			List_H.push_back(make_pair(i, j));
			break;
		case 2:
			List_C.push_back(make_pair(i, j));
			break;
		default:
			break;
		}
	}

	Sol(0, 0);
	cout << RESULT;

}
#endif


#endif
