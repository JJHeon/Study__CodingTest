#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
int V, H;
int main() {
    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    cin >> V >> H;

    vector<vector<char>> map(V, vector<char>(H, 0));
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < H; ++j) cin >> map[i][j];

    int result = 0;

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < H; ++j) {
            if (map[i][j] == 'W') continue;

            int max_dist = 0;
            vector<vector<int>> visited(V, vector<int>(H, 0));
            queue<tuple<int, int, int>> q;
            q.push(make_tuple(i, j, 1));

            while (!q.empty()) {
                auto [y, x, d] = q.front();
                q.pop();
                if (visited[y][x]) continue;
                visited[y][x] = d;
                max_dist = max(d, max_dist);

                for (int way = 0; way < 4; ++way) {
                    int next_y = y + offset_y[way];
                    int next_x = x + offset_x[way];
                    if (next_y < 0 || V <= next_y || next_x < 0 || H <= next_x) continue;
                    if (map[next_y][next_x] == 'W') continue;

                    q.push(make_tuple(next_y, next_x, d + 1));
                }
            }
            result = max(max_dist, result);
        }
    }
    if (result != 0) result -= 1;
    cout << result << "\n";
    return 0;
}