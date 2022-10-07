#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int R, C, T;
vector<vector<int>> MAP(51, vector<int>(51, 0));

const int OFFSET_Y[4] = {-1, 0, 1, 0};
const int OFFSET_X[4] = {0, 1, 0, -1};

int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> MAP[i][j];

    int c = 0;
    for (c = 0; c < T; ++c) {
        vector<vector<int>> TMAP(51, vector<int>(51, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (MAP[i][j] > 0) {
                    int count = 0;
                    int dust = MAP[i][j] / 5;
                    for (int way = 0; way < 4; ++way) {
                        int next_i = i + OFFSET_Y[way];
                        int next_j = j + OFFSET_X[way];

                        if (next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
                        if (MAP[next_i][next_j] < 0) continue;
                        count++;
                        TMAP[next_i][next_j] += dust;
                    }
                    TMAP[i][j] += (MAP[i][j] - (dust * count));
                } else if (MAP[i][j] == -1)
                    TMAP[i][j] = MAP[i][j];
            }
        }
        bool is_first = true;
        for (int i = 0; i < R; ++i) {
            if (MAP[i][0] < 0) {
                if (is_first) {
                    for (int k = i - 1; k > 0; --k)
                        TMAP[k][0] = TMAP[k - 1][0];
                    for (int k = 0; k < C - 1; ++k)
                        TMAP[0][k] = TMAP[0][k + 1];
                    for (int k = 0; k < i; ++k)
                        TMAP[k][C - 1] = TMAP[k + 1][C - 1];
                    for (int k = C - 1; k > 1; k--)
                        TMAP[i][k] = TMAP[i][k - 1];
                    TMAP[i][1] = 0;
                    is_first = false;
                } else {
                    for (int k = i + 1; k < R - 1; ++k)
                        TMAP[k][0] = TMAP[k + 1][0];
                    for (int k = 0; k < C - 1; ++k)
                        TMAP[R - 1][k] = TMAP[R - 1][k + 1];
                    for (int k = R - 1; k > i; --k)
                        TMAP[k][C - 1] = TMAP[k - 1][C - 1];
                    for (int k = C - 1; k > 1; k--)
                        TMAP[i][k] = TMAP[i][k - 1];
                    TMAP[i][1] = 0;
                }
            }
        }
        MAP.assign(TMAP.begin(), TMAP.end());
        // //DEBUG
        // printf("T : %d\n", c);
        // for (int i = 0; i < R; ++i) {
        //     for (int j = 0; j < C; ++j){
        //         printf("%2d  ", MAP[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n\n");
    }
    int result = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (MAP[i][j] > 0) result += MAP[i][j];
        }
    }
    cout << result << endl;
    return 0;
}