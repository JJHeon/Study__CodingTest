#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <cstdio>

using namespace std;

int R, C, M;

const int OFFSET_Y[4] = {-1, 0, 1, 0};
const int OFFSET_X[4] = {0, 1, 0, -1};
const int CONVERT[5] = {0, 0, 2, 1, 3};
const int REVERSE[4] = {1, 3, 2, 4};

int main() {
    cin >> R >> C >> M;
    vector<vector<int>> MAP(R + 1, vector<int>(C + 1, 0));

    vector<tuple<int, int, int>> SHARK(1);
    for (int i = 1; i <= M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        MAP[r][c] = i;
        SHARK.push_back(make_tuple(s, d, z));
    }

    int shark_get = 0;
    // 1. Move right
    for (int t = 1; t <= C; ++t) {
        // 2. Get Close Shark
        for (int j = 1; j <= R; ++j)
            if (MAP[j][t] > 0) {
                shark_get += get<2>(SHARK[MAP[j][t]]);
                MAP[j][t] = 0;
                break;
            }

        // 3. Shark Move
        vector<vector<int>> N_MAP(R + 1, vector<int>(C + 1, 0));
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (MAP[i][j] > 0) {
                    int index = MAP[i][j];
                    auto& [s, d, z] = SHARK[index];

                    // MOVE
                    int way = CONVERT[d];
                    int next_i = i + (OFFSET_Y[way] * s);
                    int next_j = j + (OFFSET_X[way] * s);

                    while (next_i < 1 || R < next_i) {
                        if (next_i < 1) {
                            next_i = ((next_i - 1) * -1) + 1;
                        } else if (R < next_i) {
                            next_i = ((R - (next_i - R)));
                        }

                        way = (way + 2) % 4;
                    }
                    while (next_j < 1 || C < next_j) {
                        if (next_j < 1) {
                            next_j = ((next_j - 1) * -1) + 1;
                        } else if (C < next_j) {
                            next_j = ((C - (next_j - C)));
                        }

                        way = (way + 2) % 4;
                    }

                    d = REVERSE[way];

                    // PREVIOUS SHARK ALREADY EXIST
                    if (N_MAP[next_i][next_j] > 0) {
                        int previous_shark_index = N_MAP[next_i][next_j];
                        int current_shark_index = index;

                        if (get<2>(SHARK[previous_shark_index]) < get<2>(SHARK[current_shark_index]))
                            N_MAP[next_i][next_j] = index;

                    } else
                        N_MAP[next_i][next_j] = index;
                }
            }
        }
        MAP.assign(N_MAP.begin(), N_MAP.end());

        // //Debug
        // printf("t : %d\n", t);
        // for (int i = 1; i <= R; ++i) {
        //     for (int j = 1; j <= C; ++j){
        //         printf("%2d ", MAP[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n\n");
    }

    cout << shark_get << "\n";

    return 0;
}