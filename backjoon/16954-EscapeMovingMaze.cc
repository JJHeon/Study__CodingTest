#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    const int offset_y[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
    const int offset_x[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};

    vector<vector<int>> map(8, vector<int>(8, 0));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            char in;
            cin >> in;

            if (in == '#') map[i][j] = -1;
        }

    queue<tuple<int, int, int>> q1;

    // q1.push(make_tuple(7, 0, 1));
    int ys = 7;
    int xs = 0;
    map[ys][xs] = 1;

    for (int way = 0; way < 9; way++) {
        int next_y = ys + offset_y[way];
        int next_x = xs + offset_x[way];
        if (next_y < 0 || 7 < next_y || next_x < 0 || 7 < next_x) continue;
        if (map[next_y][next_x] == -1) continue;

        q1.push(make_tuple(next_y, next_x, 2));
    }

    while (true) {

        while (!q1.empty()) {
            auto [y, x, c] = q1.front();
            q1.pop();
            if (map[y][x] == -1) continue;

            map[y][x] = c;
        }

        for (int j = 0; j < 8; j++) {
            for (int i = 7; i >= 0; --i) {
                if (map[i][j] != -1) continue;

                if (i == 7) {
                    map[i][j] = 0;
                } else {
                    map[i + 1][j] = map[i][j];
                    map[i][j] = 0;
                }
            }
        }

        if (map[0][7] > 0) {
            cout << "1\n";
            return 0;
        }

        bool is_alive = false;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (map[i][j] > 0) {
                    is_alive = true;

                    for (int way = 0; way < 9; way++) {
                        int next_y = i + offset_y[way];
                        int next_x = j + offset_x[way];
                        if (next_y < 0 || 7 < next_y || next_x < 0 || 7 < next_x) continue;
                        if (map[next_y][next_x] == -1) continue;

                        q1.push(make_tuple(next_y, next_x, map[i][j] + 1));
                    }
                }
            }
        }

    OUT_DOUBLE_FOR:
        if (!is_alive) {
            cout << "0\n";
            return 0;
        }
    }
    return 0;
}