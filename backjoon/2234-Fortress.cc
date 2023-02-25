#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int visit[52][52];
int mp[52][52];

int rst1;
int rst2;
int rst3;

int dw[4] = {2, 4, 8, 1};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = 1;
    int rm = 1;

    while (q.size()) {
        auto [y, x] = q.front();
        q.pop();
        for (int w = 0; w < 4; ++w) {
            if ((mp[y][x] & dw[w]) > 0) continue;
            int ny = y + dy[w];
            int nx = x + dx[w];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if (visit[ny][nx]) continue;

            q.push({ny, nx});
            visit[ny][nx] = visit[y][x] + 1;
            rm++;
        }
    }

    return rm;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> mp[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (visit[i][j]) continue;
            rst1++;
            rst2 = max(bfs(i, j), rst2);
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int w = 0; w < 4; ++w) {
                if (mp[i][j] & (1 << w)) {
                    mp[i][j] = mp[i][j] ^ (1 << w);
                    memset(visit, 0, sizeof(visit));
                    for (int ii = 0; ii < n; ++ii) {
                        for (int jj = 0; jj < m; ++jj) {
                            if (visit[i][j]) continue;
                            rst3 = max(bfs(i, j), rst3);
                        }
                    }
                    mp[i][j] = mp[i][j] ^ (1 << w);
                }
            }
        }

    cout << rst1 << "\n"
         << rst2 << "\n"
         << rst3;

    return 0;
}