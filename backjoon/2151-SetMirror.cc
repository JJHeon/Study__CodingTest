#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N;
vector<vector<int>> HOME;

int main() {
    cin >> N;

    HOME.resize(N, vector<int>(N, 0));
    char in;
    bool is_first = true;

    int start_y, start_x, end_y, end_x;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> in;
            if (in == '*')
                HOME[i][j] = -1;  //-1 : 벽
            else if (in == '!')
                HOME[i][j] = -2;  //-2 : 문
            else if (in == '#') {
                if (is_first) {
                    start_y = i;
                    start_x = j;
                    is_first = false;
                } else {
                    end_y = i;
                    end_x = j;
                }
            }
        }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(start_y, start_x, 1));
    HOME[start_y][start_x] = 1;

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();
        if (y == end_y && x == end_x) break;

        for (int way = 0; way < 4; way++) {
            int next_y = y + offset_y[way];
            int next_x = x + offset_x[way];
            if (next_y < 0 || N <= next_y || next_x < 0 || N <= next_y) continue;
            if (HOME[next_y][next_x] == -1) continue;

            switch (way) {
                case 0:
                    for (int i = next_y; i >= 0; i--) {
                        if (HOME[i][next_x] == -1) break;
                        if (HOME[i][next_x] == -2) q.push(make_tuple(i, next_x, c + 1));
                        if (HOME[i][next_x] > 0 && HOME[i][next_x] < c) continue;
                        HOME[i][next_x] = c;
                    }
                    break;
                case 1:
                    for (int j = next_x; j < N; j++) {
                        if (HOME[next_y][j] == -1) break;
                        if (HOME[next_y][j] == -2) q.push(make_tuple(next_y, j, c + 1));
                        if (HOME[next_y][j] > 0 && HOME[next_y][j] < c) continue;
                        HOME[next_y][j] = c;
                    }
                    break;
                case 2:
                    for (int i = next_y; i < N; i++) {
                        if (HOME[i][next_x] == -1) break;
                        if (HOME[i][next_x] == -2) q.push(make_tuple(i, next_x, c + 1));
                        if (HOME[i][next_x] > 0 && HOME[i][next_x] < c) continue;
                        HOME[i][next_x] = c;
                    }
                    break;
                case 3:
                    for (int j = next_x; j >= 0; j--) {
                        if (HOME[next_y][j] == -1) break;
                        if (HOME[next_y][j] == -2) q.push(make_tuple(next_y, j, c + 1));
                        if (HOME[next_y][j] > 0 && HOME[next_y][j] < c) continue;
                        HOME[next_y][j] = c;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    cout << HOME[end_y][end_x] - 1 << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; ++j) {
    //         printf("%2d ", HOME[i][j]);
    //     }
    //     cout << endl;
    // }

    return 0;
}