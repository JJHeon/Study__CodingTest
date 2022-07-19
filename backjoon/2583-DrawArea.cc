#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    vector<int> result_all;
    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> map(m, vector<int>(n, 0));

    for (int kc = 0; kc < k; ++kc) {
        int start_y, start_x, end_y, end_x;

        cin >> start_x >> start_y >> end_x >> end_y;

        for (int y = start_y; y < end_y; ++y) {
            for (int x = start_x; x < end_x; ++x) {
                map[y][x] = 1;
            }
        }
    }

    int count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j])
                continue;
            else if (visited[i][j])
                continue;

            count++;

            queue<tuple<int, int, int>> q;
            q.push(make_tuple(i, j, 1));
            int maximum = 0;
            while (!q.empty()) {
                auto [y, x, c] = q.front();
                q.pop();
                if (visited[y][x]) continue;

                visited[y][x] = true;
                maximum++;

                for (int way = 0; way < 4; way++) {
                    int next_y = y + offset_y[way];
                    int next_x = x + offset_x[way];

                    if (next_y < 0 || m <= next_y || next_x < 0 || n <= next_x) continue;
                    if (map[next_y][next_x] == 1) continue;

                    q.push(make_tuple(next_y, next_x, c + 1));
                }
            }
            result_all.push_back(maximum);
        }
    }

    sort(result_all.begin(), result_all.end());

    cout << count << "\n";
    for (auto v : result_all) cout << v << " ";
    cout << "\n";

    return 0;
}