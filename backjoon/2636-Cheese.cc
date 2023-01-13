#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;
int map[104][104];
int last_cheese;
int sec = 0;

int main() {
    // input
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    while (true) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> hole;
        bool visit[104][104];
        fill(&visit[0][0], &visit[0][0] + 104 * 104, 0);
        visit[0][0] = true;
        q.push({0, 0});

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];
                if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
                if (visit[ny][nx]) continue;

                visit[ny][nx] = true;
                if (map[ny][nx] == 1)
                    hole.push_back({ny, nx});
                else
                    q.push({ny, nx});
            }
        }

        if (hole.size() == 0) break;
        last_cheese = hole.size();

        for (auto item : hole) {
            auto [y, x] = item;

            map[y][x] = 0;
        }
        sec++;

        // debug
        // cout << sec << " : \n";
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }

    cout << sec << "\n";
    cout << last_cheese << "\n";
}