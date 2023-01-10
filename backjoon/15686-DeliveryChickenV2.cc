#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstdint>

using namespace std;

int n, m;
int map[52][52];
int dist[15][52][52];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];

            if (map[i][j] == 1)
                home.push_back({i, j});
            else if (map[i][j] == 2)
                chicken.push_back({i, j});
        }
    }

    for (int i = 0; i < chicken.size(); ++i) {
        auto [y, x] = chicken[i];

        queue<pair<int, int>> q;
        dist[i][y][x] = 1;
        q.push({y, x});
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];

                if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
                if (dist[i][ny][nx]) continue;

                dist[i][ny][nx] = dist[i][y][x] + 1;
                q.push({ny, nx});
            }
        }

        // cout << "\n";
        // for (int d1 = 0; d1 < n; ++d1) {
        //     for (int d2 = 0; d2 < n; ++d2) cout << dist[i][d1][d2] << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }

    vector<int> pick;
    for (int i = 0; i < chicken.size(); ++i) {
        if (i <= m - 1)
            pick.push_back(0);
        else
            pick.push_back(1);
    }

    int result = INT32_MAX;
    do {
        // // debug
        // for (int d = 0; d < pick.size(); ++d) cout << pick[d] << " ";
        // cout << "\n";

        int city = 0;
        for (int h = 0; h < home.size(); ++h) {
            int minimum = INT32_MAX;
            auto [y, x] = home[h];

            for (int i = 0; i < pick.size(); ++i) {
                if (pick[i]) continue;

                // cout << dist[i][y][x] << "\n";
                minimum = min(minimum, dist[i][y][x] - 1);
            }
            city += minimum;
        }
        result = min(result, city);
    } while (next_permutation(pick.begin(), pick.end()));

    cout << result << "\n";
    return 0;
}