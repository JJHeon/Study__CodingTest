/*
@Title		: 백준
@Name		: 나무 재태크
@First0		: 21.03.18
@Revision1	:
@ETC		:
항상 Top이 최신 코드
*/

#define __BACKJOON_16235__ 1  // 21.03.18	//나무 재태크

#if __BACKJOON_16235__

// 0
#if 1
#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>
#include <utility>
using namespace std;

int TREE[11][11][1001];
int MAP[11][11];
int DMAP[11][11];
int ADDER[11][11];

int DIR_I[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int DIR_J[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N, M, K;
vector<pair<int, int>> V;
vector<pair<int, int>> Q;

bool Func(int i, int j, int* l) {
    // Spring
    for (int k = TREE[i][j][0]; k > 0; k--) {
        if (MAP[i][j] - TREE[i][j][k] < 0) {
            // Summer
            for (int z = 1; z <= k; z++) DMAP[i][j] += (TREE[i][j][z] / 2);

            for (int u = k + 1; u <= TREE[i][j][0]; u++) TREE[i][j][u - k] = TREE[i][j][u];
            TREE[i][j][0] = TREE[i][j][0] - k;

            if (TREE[i][j][0] == 0) {
                for (int q = (*l); q < V.size() - 1; q++) V[q] = V[q + 1];
                V.pop_back();
                (*l)--;
                return false;
            }
            break;
        }

        MAP[i][j] -= (TREE[i][j][k]++);
    }

    return true;
}

int main() {
    V.reserve(sizeof(pair<int, int>) * 100);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            cin >> ADDER[i][j];
            MAP[i][j] = 5;
        }
    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        TREE[x][y][1] = z;
        TREE[x][y][0] = 1;
        V.push_back(make_pair(x, y));
    }

    while (K-- != 0) {
        memset(DMAP, 0, sizeof(DMAP));
        for (int l = 0; l < V.size(); l++) {
            int i = V[l].first;
            int j = V[l].second;

            if (Func(i, j, &l)) {
                for (int u = 1; u <= TREE[i][j][0]; u++) {
                    if (TREE[i][j][u] % 5 != 0) continue;

                    for (int w = 0; w < 8; w++) {
                        int nI = i + DIR_I[w];
                        int nJ = j + DIR_J[w];
                        if (nI <= 0 || nI > N || nJ <= 0 || nJ > N) continue;

                        Q.push_back(make_pair(nI, nJ));
                    }
                }
            }

            // Winter
            MAP[i][j] += DMAP[i][j];
        }

        for (int v = 0; v < Q.size(); v++) {
            int i = Q[v].first;
            int j = Q[v].second;

            if (TREE[i][j][0] == 0) V.push_back(make_pair(i, j));
            TREE[i][j][++TREE[i][j][0]] = 1;
        }
        Q.clear();
        // Winter
        for (int v = 1; v <= N; v++)
            for (int w = 1; w <= N; w++) MAP[v][w] += ADDER[v][w];
    }

    int RES = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) RES += TREE[i][j][0];

    cout << RES;
}
#endif
#endif
