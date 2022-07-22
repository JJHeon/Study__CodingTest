#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    constexpr int kWall = -1;

    int h, w;
    cin >> w >> h;

    vector<vector<int>> map(h, vector<int>(w, 0));
    bool input_flag = false;
    int target_start_y = 0;
    int target_start_x = 0;
    int target_end_y = 0;
    int target_end_x = 0;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char in;
            cin >> in;
            if (in == '*')
                map[i][j] = kWall;
            else if (in == 'C') {
                if (!input_flag) {
                    target_start_y = i;
                    target_start_x = j;
                    input_flag = true;
                } else {
                    target_end_y = i;
                    target_end_x = j;
                }
            }
        }
    }
    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    queue<tuple<int, int, int>> q;
    map[target_start_y][target_start_x] = 1;
    q.push(make_tuple(target_start_y, target_start_x, 1));

    int result = 0;
    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();
        if (y == target_end_y && x == target_end_x) {
            result = c;
            break;
        }

        for (int way = 0; way < 4; ++way) {
            int next_y = y + offset_y[way];
            int next_x = x + offset_x[way];

            if (next_y < 0 || h <= next_y || next_x < 0 || w <= next_x) continue;
            if (map[next_y][next_x] == -1) continue;
            if (map[next_y][next_x] != 0 && map[next_y][next_x] < c) continue;

            switch (way) {
                case 0:
                    for (int i = next_y; i >= 0; i--) {
                        if (map[i][next_x] == -1) break;
                        if (map[i][next_x] != 0 && map[i][next_x] < c) continue;
                        map[i][next_x] = c;
                        q.push(make_tuple(i, next_x, c + 1));
                    }
                    break;
                case 1:
                    for (int j = next_x; j < w; ++j) {
                        if (map[next_y][j] == -1) break;
                        if (map[next_y][j] != 0 && map[next_y][j] < c) continue;
                        map[next_y][j] = c;
                        q.push(make_tuple(next_y, j, c + 1));
                    }
                    break;
                case 2:
                    for (int i = next_y; i < h; ++i) {
                        if (map[i][next_x] == -1) break;
                        if (map[i][next_x] != 0 && map[i][next_x] < c) continue;
                        map[i][next_x] = c;
                        q.push(make_tuple(i, next_x, c + 1));
                    }
                    break;
                case 3:
                    for (int j = next_x; j >= 0; j--) {
                        if (map[next_y][j] == -1) break;
                        if (map[next_y][j] != 0 && map[next_y][j] < c) continue;
                        map[next_y][j] = c;
                        q.push(make_tuple(next_y, j, c + 1));
                    }
                    break;

                default:
                    break;
            }
        }
    }
    cout << map[target_end_y][target_end_x] - 1 << "\n";
    // for (int i = 0; i < h; ++i) {
    //     for (int j = 0; j < w; ++j) printf("%2d ", map[i][j]);
    //     cout << "\n";
    // }
    return 0;
}