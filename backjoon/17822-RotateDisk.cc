#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;
int N, M, T;
int MAP[51][51];

int main() {
    cin >> N >> M >> T;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) cin >> MAP[i][j];

    for (int i = 0; i < T; ++i) {
        int x, d, k;
        cin >> x >> d >> k;

        // 1. 회전
        for (int disk = x; disk <= N; disk += x) {
            if (d == 0) {
                int arr[51] = {
                    0,
                };
                for (int i = 1; i <= M; ++i) {
                    int next_i = ((i - 1) + k) % M + 1;
                    arr[next_i] = MAP[disk][i];
                }
                memcpy(MAP[disk], arr, sizeof(arr));
            } else if (d == 1) {
                int arr[51] = {
                    0,
                };
                for (int i = 1; i <= M; ++i) {
                    int next_i = ((i - 1) + (M - (k % M))) % M + 1;
                    arr[next_i] = MAP[disk][i];
                }
                memcpy(MAP[disk], arr, sizeof(arr));
            }
        }

        // // debug
        // printf("Rotate\n");
        // for (int i = 1; i <= N; ++i) {
        //     for (int j = 1; j <= M; ++j) printf("%2d ", MAP[i][j]);
        //     printf("\n");
        // }
        // printf("\n");

        // 2. Check Num
        int VMAP[51][51];
        memcpy(VMAP, MAP, sizeof(VMAP));
        bool is_exist = false;
        for (int disk = 1; disk <= N; disk++) {
            for (int i = 1; i <= M; ++i) {
                int origin = MAP[disk][i];
                if (origin == 0) continue;
                int right_i = ((i - 1) + 1) % M + 1;
                int left_i = ((i - 1) + (M - 1)) % M + 1;
                int bottom_d_idx = disk - 1;
                int top_d_idx = disk + 1;

                if (origin == MAP[disk][right_i]) {
                    VMAP[disk][i] = 0;
                    VMAP[disk][right_i] = 0;
                    is_exist = true;
                    // printf("callright %d, %d | %d, %d\n", disk, i, disk, right_i);
                }
                if (origin == MAP[disk][left_i]) {
                    VMAP[disk][i] = 0;
                    VMAP[disk][left_i] = 0;
                    is_exist = true;
                    // printf("callleft %d, %d | %d, %d\n", disk, i, disk, left_i);
                }
                if (top_d_idx <= N && origin == MAP[top_d_idx][i]) {
                    VMAP[disk][i] = 0;
                    VMAP[top_d_idx][i] = 0;
                    is_exist = true;
                    // printf("calltop %d, %d | %d, %d\n", disk, i, top_d_idx, i);
                }
                if (bottom_d_idx >= 1 && origin == MAP[bottom_d_idx][i]) {
                    VMAP[disk][i] = 0;
                    VMAP[bottom_d_idx][i] = 0;
                    is_exist = true;
                    // printf("callbottom %d, %d | %d, %d\n", disk, i, bottom_d_idx, i);
                }
            }
        }
        if (!is_exist) {
            int sum = 0;
            int num = 0;
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    if (VMAP[i][j] == 0) continue;
                    num++;
                    sum += VMAP[i][j];
                }
            }
            double criteria = sum / (double)num;
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    if (VMAP[i][j] == 0) continue;

                    if ((double)VMAP[i][j] < criteria)
                        VMAP[i][j] += 1;
                    else if ((double)VMAP[i][j] > criteria)
                        VMAP[i][j] -= 1;
                }
            }
        }
        memcpy(MAP, VMAP, sizeof(VMAP));

        // // debug
        // printf("checkNum\n");
        // for (int i = 1; i <= N; ++i) {
        //     for (int j = 1; j <= M; ++j) printf("%2d ", MAP[i][j]);
        //     printf("\n");
        // }
        // printf("\n\n\n");
    }
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            sum += MAP[i][j];
        }
    }
    cout << sum << "\n";
    return 0;
}