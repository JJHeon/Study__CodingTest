#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<tuple<int, int, int>> q;

    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int in;
            cin >> in;

            if (in < 0)
                visited[i][j] = -1;
            else if (in > 0)
                q.push(make_tuple(i, j, 1));
            else
                count++;
        }
    if (count == 0 && !q.empty()) {
        cout << "0\n";
        return 0;
    }

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();
        if (visited[y][x] != 0) continue;

        visited[y][x] = c;

        for (int way = 0; way < 4; ++way) {
            int next_y = y + offset_y[way];
            int next_x = x + offset_x[way];

            if (next_y < 0 || n <= next_y || next_x < 0 || m <= next_x) continue;
            if (visited[next_y][next_x] != 0) continue;
            q.push(make_tuple(next_y, next_x, c + 1));
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] == 0) {
                cout << "-1\n";
                return 0;
            }
            result = max(result, visited[i][j]);
        }
    }
    if (result != 0) result -= 1;
    cout << result << "\n";

    return 0;
}