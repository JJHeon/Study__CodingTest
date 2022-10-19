#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int R, C, K;
int MAP[101][101];
int main() {
    cin >> R >> C >> K;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) cin >> MAP[i][j];

    bool is_finish = false;
    int num_row = 3;
    int num_col = 3;
    for (int t = 0; t <= 100; ++t) {
        if (MAP[R][C] == K) {
            cout << t << "\n";
            is_finish = true;
            break;
        }

        if (num_row >= num_col) {
            int new_num_col = 0;

            // Cal R
            for (int r = 1; r <= num_row; ++r) {
                vector<pair<int, int>> list(101, pair<int, int>(INT32_MAX, INT32_MAX));

                // Count
                for (int j = 1; j <= num_col; ++j) {
                    // MAP[r][j]
                    int v = MAP[r][j];
                    if (v == 0) continue;

                    int& num = list[v].first;
                    int& num_count = list[v].second;
                    if (num == INT32_MAX) {
                        num = v;
                        num_count = 1;
                    } else
                        num_count++;
                }

                stable_sort(list.begin(), list.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
                    if (a.second == b.second)
                        return a.first < b.first;
                    else
                        return a.second < b.second;
                });

                // printf("---------------\n");
                // int tmi = 1;
                // for (auto p : list) {
                //     if (p.first == INT32_MAX) break;
                //     printf("%d : %3d, %3d \n", tmi++, p.first, p.second);
                // }
                // printf("End------------\n");

                int new_idx = 0;
                memset(MAP[r], 0, 101 * sizeof(int));
                // for (int j2 = 0; j2 <= 100; ++j2) MAP[r][j2] = 0;

                for (int idx = 0; idx <= 100; ++idx) {
                    if (list[idx].first == INT32_MAX || new_idx > 100) break;
                    int num = list[idx].first;
                    int num_count = list[idx].second;

                    MAP[r][++new_idx] = num;
                    MAP[r][++new_idx] = num_count;
                    new_num_col = max(new_num_col, new_idx);
                }
            }

            num_col = new_num_col;
        } else if (num_row < num_col) {
            int new_num_row = 0;
            // Cal C
            for (int c = 1; c <= num_col; ++c) {
                vector<pair<int, int>> list(101, pair<int, int>(INT32_MAX, INT32_MAX));

                for (int i = 1; i <= num_row; ++i) {
                    int v = MAP[i][c];
                    if (v == 0) continue;

                    int& num = list[v].first;
                    int& num_count = list[v].second;
                    if (num == INT32_MAX) {
                        num = v;
                        num_count = 1;
                    } else
                        num_count++;
                }

                stable_sort(list.begin(), list.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
                    if (a.second == b.second)
                        return a.first < b.first;
                    else
                        return a.second < b.second;
                });

                int new_idx = 0;
                for (int i2 = 0; i2 <= 100; ++i2) MAP[i2][c] = 0;

                for (int idx = 0; idx <= 100; ++idx) {
                    if (list[idx].first == INT32_MAX || new_idx > 100) break;
                    int num = list[idx].first;
                    int num_count = list[idx].second;

                    MAP[++new_idx][c] = num;
                    MAP[++new_idx][c] = num_count;
                    new_num_row = max(new_num_row, new_idx);
                }
            }
            num_row = new_num_row;
        }

        // // Debug
        // printf("\n\nT : %d, num_row : %d, num_col : %d\n", t + 1, num_row, num_col);
        // for (int i = 1; i <= num_row; ++i) {
        //     for (int j = 1; j <= num_col; ++j) printf("%3d ", MAP[i][j]);
        //     printf("\n");
        // }
    }
    if (!is_finish) cout << "-1\n";

    return 0;
}