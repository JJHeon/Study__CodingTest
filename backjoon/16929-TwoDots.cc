#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M;

int main() {
    string result = "No";

    cin >> N >> M;

    vector<vector<char>> board(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    const int offset_y[4] = {0, 1, 0, -1};
    const int offset_x[4] = {1, 0, -1, 0};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char color = board[i][j];
            int start_y = i;
            int start_x = j;

            // cout << i << " " << j << " H" << endl;
            queue<tuple<int, int, int>> q;

            if (j + 1 >= M)
                continue;
            else if (board[i][j + 1] != color)
                continue;

            q.push(make_tuple(i, j + 1, 0));

            while (!q.empty()) {
                auto [y, x, w] = q.front();
                q.pop();
                if (start_y == y && start_x == x) {
                    result = "Yes";
                    goto FINISH;
                }
                // cout << y << " " << x << " " << w << endl;
                int lst[3] = {w, (w + 1) % 4, (w + 3) % 4};

                for (int k = 0; k < 3; ++k) {
                    int next_y = y + offset_y[lst[k]];
                    int next_x = x + offset_x[lst[k]];
                    if (next_y < 0 || N <= next_y || next_x < 0 || M <= next_x) continue;
                    if (board[next_y][next_x] != color) continue;

                    q.push(make_tuple(next_y, next_x, lst[k]));
                }
            }
            // cout << "\n\n";
        }
    }

FINISH:
    cout << result << endl;

    return 0;
}