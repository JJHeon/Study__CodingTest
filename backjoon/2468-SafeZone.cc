#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    int RESLT = 0;
    vector<vector<int>> MAP(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> MAP[i][j];

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    for (int h = 0; h <= 100; ++h) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        int count = 0;

        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (visited[y][x]) continue;
                if (MAP[y][x] == -1) continue;
                if (MAP[y][x] <= h) {
                    MAP[y][x] = -1;
                    continue;
                }

                count++;
                queue<pair<int, int>> q;

                q.push(make_pair(y, x));
                while (!q.empty()) {
                    auto [i, j] = q.front();
                    q.pop();
                    if (visited[i][j]) continue;

                    visited[i][j] = true;

                    for (int way = 0; way < 4; ++way) {
                        int next_i = i + offset_y[way];
                        int next_j = j + offset_x[way];
                        if (next_i < 0 || N <= next_i || next_j < 0 || N <= next_j) continue;
                        if (MAP[next_i][next_j] <= h) continue;

                        q.push(make_pair(next_i, next_j));
                    }
                }
            }
        }

        RESLT = max(RESLT, count);
        // cout << "\n\n";
        // cout << h << " " << RESLT << endl;
        // for (int y = 0; y < N; ++y) {
        //     for (int x = 0; x < N; ++x) cout << MAP[y][x] << " ";
        //     cout << "\n";
        // }
    }

    cout << RESLT << "\n";
    return 0;
}