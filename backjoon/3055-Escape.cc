#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int R, C;

int main() {
    cin >> R >> C;

    vector<vector<int>> MAP(R, vector<int>(C, 0));
    int start_y, start_x;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char in;
            cin >> in;
            if (in == 'D')
                MAP[i][j] = -2;
            else if (in == '*')
                MAP[i][j] = -1;
            else if (in == 'S') {
                start_y = i;
                start_x = j;
                MAP[i][j] = 1;
            } else if (in == 'X')
                MAP[i][j] = -3;
        }
    }

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    int time = 0;
    while (true) {
        time += 1;

        queue<tuple<int, int, int>> q2;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (MAP[i][j] > 0) q2.push(make_tuple(i, j, MAP[i][j]));
            }
        }

        if (q2.empty()) {
            cout << "KAKTUS\n";
            break;
        }

        while (!q2.empty()) {
            auto [y, x, c] = q2.front();

            q2.pop();

            for (int way = 0; way < 4; ++way) {
                int next_y = y + offset_y[way];
                int next_x = x + offset_x[way];
                if (next_y < 0 || R <= next_y || next_x < 0 || C <= next_x) continue;
                if (MAP[next_y][next_x] == -1) continue;
                if (MAP[next_y][next_x] > 0) continue;
                if (MAP[next_y][next_x] == -3) continue;

                if (MAP[next_y][next_x] == -2) {
                    cout << time << endl;
                    goto FINISH;
                } else
                    MAP[next_y][next_x] = c + 1;
            }
        }

        queue<pair<int, int>> q1;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (MAP[i][j] == -1)
                    q1.push(make_pair(i, j));
            }
        }

        while (!q1.empty()) {
            auto [y, x] = q1.front();
            q1.pop();

            for (int way = 0; way < 4; ++way) {
                int next_y = y + offset_y[way];
                int next_x = x + offset_x[way];
                if (next_y < 0 || R <= next_y || next_x < 0 || C <= next_x) continue;
                if (MAP[next_y][next_x] == -2) continue;
                if(MAP[next_y][next_x] == -3) continue;

                MAP[next_y][next_x] = -1;
            }
        }

        // cout << time << endl;
        // for (int i = 0; i < R; ++i) {
        //     for (int j = 0; j < C; ++j) {
        //         printf("%2d ", MAP[i][j]);
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }
FINISH:
    return 0;
}