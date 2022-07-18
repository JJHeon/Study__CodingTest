#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    const int offset_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int offset_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int t;
    cin >> t;

    vector<int> result_all;

    for (int tc = 0; tc < t; tc++) {
        int result = 0;
        int len = 0;
        int start_y, start_x;
        int end_y, end_x;

        cin >> len;
        cin >> start_y >> start_x;
        cin >> end_y >> end_x;

        vector<vector<int>> visited(len, vector<int>(len, 0));
        queue<tuple<int, int, int>> q;

        q.push(make_tuple(start_y, start_x, 1));
        while (!q.empty()) {
            auto [y, x, c] = q.front();
            q.pop();
            if (y == end_y && x == end_x) {
                result = c - 1;
                break;
            }
            if (visited[y][x]) continue;

            visited[y][x] = c;

            for (int way = 0; way < 8; ++way) {
                int next_y = y + offset_y[way];
                int next_x = x + offset_x[way];

                if (next_y < 0 || len <= next_y || next_x < 0 || len <= next_x) continue;
                if (visited[next_y][next_x]) continue;

                q.push(make_tuple(next_y, next_x, c + 1));
            }
        }

        if (result < 0) result = 0;
        result_all.push_back(result);
    }
    for (auto r : result_all) cout << r << "\n";

    return 0;
}