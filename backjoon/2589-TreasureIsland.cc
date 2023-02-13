#include <iostream>

#include <string>

#include <algorithm>

#include <queue>

#include <tuple>

using namespace std;

int n, m;
string s[52];
int visited[52][52];
int rst;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs(int i, int j) {
    int mx = 0;
    queue<tuple<int, int, int>> q;

    visited[i][j] = 1;
    q.push(make_tuple(i, j, 1));

    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();

        for (int w = 0; w < 4; ++w) {
            int ny = y + dy[w];
            int nx = x + dx[w];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
            if (s[ny][nx] == 'W') continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = c + 1;
            q.push(make_tuple(ny, nx, c + 1));
            mx = max(mx, c + 1);
        }
    }

    return mx - 1 < 0 ? 0 : mx - 1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)

        cin >> s[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'L') {
                fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);

                rst = max(bfs(i, j), rst);
            }
        }
    }

    cout << rst;

    return 0;
}