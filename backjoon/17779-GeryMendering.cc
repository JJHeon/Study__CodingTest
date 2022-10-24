#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
#include <algorithm>
#include <cstdint>

using namespace std;
int N;
int MAP[21][21];
int SECTOR[21][21];
int PEOPLE[6];
int RESULT = INT32_MAX;
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) cin >> MAP[i][j];

    for (int d1 = 1; d1 <= N; ++d1) {
        for (int d2 = 1; d2 <= N; ++d2) {
            for (int x = 1; x + d1 + d2 <= N; ++x) {
                for (int y = 2; y + d2 <= N; ++y) {
                    if (1 > y - d1 || y + d2 > N) continue;
                    memset(SECTOR, 0, sizeof(SECTOR));
                    memset(PEOPLE, 0, sizeof(PEOPLE));
                    bool is_out = false;
                    // boundary 1
                    SECTOR[x][y] = 5;
                    int b1_x = x + 1;
                    int b1_y = y - 1;
                    while (b1_x <= x + d1 && b1_y >= y - d1) {
                        if (b1_x > N || b1_y < 1) {
                            is_out = true;
                            break;
                        }
                        SECTOR[b1_x][b1_y] = 5;

                        ++b1_x;
                        --b1_y;
                    }

                    // boundary 2
                    int b2_x = x + 1;
                    int b2_y = y + 1;
                    while (b2_x <= x + d2 && b2_y <= y + d2) {
                        if (b2_x > N || b2_y > N) {
                            is_out = true;
                            break;
                        }
                        SECTOR[b2_x][b2_y] = 5;
                        ++b2_x;
                        ++b2_y;
                    }

                    // boundary 3
                    int b3_x = x + d1;
                    int b3_y = y - d1;
                    while (b3_x <= x + d1 + d2 && b3_y <= y - d1 + d2) {
                        if (b3_x > N || b3_y > N) {
                            is_out = true;
                            break;
                        }
                        SECTOR[b3_x][b3_y] = 5;
                        ++b3_x;
                        ++b3_y;
                    }

                    // boundary 4
                    int b4_x = x + d2;
                    int b4_y = y + d2;
                    while (b4_x <= x + d2 + d1 && b4_y >= y + d2 - d1) {
                        if (b4_x > N || b4_y < 1) {
                            is_out = true;
                            break;
                        }
                        SECTOR[b4_x][b4_y] = 5;
                        ++b4_x;
                        --b4_y;
                    }
                    if (is_out) continue;

                    // 3
                    for (int i = 1; i <= N; ++i) {
                        bool is_sector5 = false;
                        int start_j = 0;
                        int end_j = 0;
                        for (int j = 1; j <= N; ++j) {
                            if (SECTOR[i][j] == 5 && !is_sector5) {
                                is_sector5 = true;
                                start_j = j;
                            } else if (SECTOR[i][j] == 5 && is_sector5) {
                                is_sector5 = false;
                                end_j = j;
                            }
                        }

                        if (end_j != 0) {
                            for (int j = start_j + 1; j <= end_j; ++j) {
                                SECTOR[i][j] = 5;
                            }
                        }
                    }

                    // 4-1
                    for (int r = 1; r < x + d1; r++) {
                        for (int c = 1; c <= y; ++c) {
                            if (SECTOR[r][c] == 5) continue;
                            SECTOR[r][c] = 1;
                        }
                    }
                    // 4-2
                    for (int r = 1; r <= x + d2; ++r) {
                        for (int c = y + 1; c <= N; ++c) {
                            if (SECTOR[r][c] == 5) continue;
                            SECTOR[r][c] = 2;
                        }
                    }
                    // 4-3
                    for (int r = x + d1; r <= N; ++r) {
                        for (int c = 1; c < y - d1 + d2; ++c) {
                            if (SECTOR[r][c] == 5) continue;
                            SECTOR[r][c] = 3;
                        }
                    }
                    // 4-4
                    for (int r = x + d2 + 1; r <= N; ++r) {
                        for (int c = y - d1 + d2; c <= N; ++c) {
                            if (SECTOR[r][c] == 5) continue;
                            SECTOR[r][c] = 4;
                        }
                    }

                    // Sum
                    for (int i = 1; i <= N; ++i) {
                        for (int j = 1; j <= N; ++j) {
                            PEOPLE[SECTOR[i][j]] += MAP[i][j];
                        }
                    }

                    int maximum = 0;
                    int minimum = INT32_MAX;
                    for (int way = 1; way <= 5; ++way) {
                        maximum = max(maximum, PEOPLE[way]);
                        minimum = min(minimum, PEOPLE[way]);
                    }

                    // // DEBUG
                    // cout << "\n\nx, y, d1, d2 : " << x << ", " << y << ", " << d1 << ", " << d2 << "\n";
                    // for (int i = 1; i <= N; ++i) {
                    //     for (int j = 1; j <= N; ++j) {
                    //         printf("%d ", SECTOR[i][j]);
                    //     }
                    //     cout << "\n";
                    // }
                    // cout << "max : " << maximum << ", min : " << minimum << "\n";

                    RESULT = min(RESULT, maximum - minimum);
                }
            }
        }
    }

    cout << RESULT << "\n";
    return 0;
}