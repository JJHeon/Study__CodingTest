#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int N;
vector<vector<int>> MAP;
int main() {
    const int offset_y[4] = {0, -1, 1, 0};
    const int offset_x[4] = {-1, 0, 0, 1};
    int baby_y, baby_x, baby = 2;
    int time = 0;
    int eat = 0;

    cin >> N;

    MAP.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int in;
            cin >> in;
            MAP[i][j] = in;
            if (in == 9) {
                baby_y = i;
                baby_x = j;
            }
        }

    while (true) {
        vector<vector<int>> visited(N, vector<int>(N, 0));
        queue<tuple<int, int, int>> q;
        bool is_eated = false;

        q.push(make_tuple(baby_y, baby_x, 1));

        while (!q.empty()) {
            auto [y, x, c] = q.front();
            q.pop();
            if (MAP[y][x] != 9 && MAP[y][x] > baby) continue;
            if (visited[y][x]) continue;

            // if (MAP[y][x] != 9 && MAP[y][x] > 0 && MAP[y][x] < baby) {
            //     time += (c - 1);
            //     MAP[baby_y][baby_x] = 0;
            //     MAP[y][x] = 9;
            //     baby_y = y;
            //     baby_x = x;
            //     is_eated = true;
            //     eat += 1;
            //     if (eat == baby) {
            //         baby += 1;
            //         eat = 0;
            //     }

            //     cout << endl;
            //     cout << time << " " << baby << " " << eat << endl;

            //     for (int i = 0; i < N; i++) {
            //         for (int j = 0; j < N; j++) {
            //             cout << MAP[i][j] << " ";
            //         }
            //         cout << endl;
            //     }
            //     cout << "\n\n";
            //     break;
            // }
            // cout << y << " " << x << " " << c << endl;
            visited[y][x] = c;

            for (int way = 0; way < 4; ++way) {
                int next_y = y + offset_y[way];
                int next_x = x + offset_x[way];

                if (next_y < 0 || N <= next_y || next_x < 0 || N <= next_x) continue;
                if (MAP[next_y][next_x] == 9) continue;

                q.push(make_tuple(next_y, next_x, c + 1));
            }
        }
        int minimum = INT32_MAX;
        int min_y;
        int min_x;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visited[i][j] > 0 && MAP[i][j] != 0 && MAP[i][j] != 9 && MAP[i][j] < baby && minimum > visited[i][j]) {
                    minimum = min(minimum, visited[i][j]);
                    min_y = i;
                    min_x = j;
                    is_eated = true;
                }
            }
        }

        if (is_eated) {
            time += (visited[min_y][min_x] - 1);
            MAP[baby_y][baby_x] = 0;
            MAP[min_y][min_x] = 9;
            baby_y = min_y;
            baby_x = min_x;
            eat += 1;
            if (eat == baby) {
                baby += 1;
                eat = 0;
            }

            // cout << time << " " << baby << " " << eat << endl;
            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < N; j++) {
            //         cout << MAP[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << "\n\n";
        } else {
            break;
        }
    }

    cout << time << endl;
    return 0;
}