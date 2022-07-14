#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int main() {
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> map[i][j];

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};
    int result = 0;
    while (true) {
        //--
        vector<vector<int>> next_map(N, vector<int>(M, 0));
        bool is_melting_all = true;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!map[i][j]) continue;
                int sea = 0;
                for (int way = 0; way < 4; ++way) {
                    int next_i = i + offset_y[way];
                    int next_j = j + offset_x[way];
                    if (next_i < 0 || N <= next_i || next_j < 0 || M <= next_j) continue;
                    if (map[next_i][next_j]) continue;
                    sea++;
                }
                next_map[i][j] = map[i][j] - sea < 0 ? 0 : map[i][j] - sea;
                if (next_map[i][j]) is_melting_all = false;
            }
        }
        //모두 녹은 경우
        if (is_melting_all) {
            result = 0;
            break;
        }
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (!next_map[i][j]) continue;
                if (visited[i][j]) continue;

                count++;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();
                    if (visited[y][x]) continue;

                    visited[y][x] = true;

                    for (int way = 0; way < 4; way++) {
                        int next_y = y + offset_y[way];
                        int next_x = x + offset_x[way];
                        if (next_y < 0 || N <= next_y || next_x < 0 || M <= next_x) continue;
                        if (!next_map[next_y][next_x]) continue;

                        q.push(make_pair(next_y, next_x));
                    }
                }
            }
        }
        result++;
        map.assign(next_map.begin(), next_map.end());
        // exit
        if (count >= 2)
            break;
    }
    cout << result << "\n";
    return 0;
}