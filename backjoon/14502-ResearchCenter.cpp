#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;
int mp[10][10];
int visited[10][10];
int rst;
vector<pair<int, int>> virus;

void dfs(int y, int x, int c) {
    if (c == 3) {
        fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
        queue<pair<int, int>> q;

        for (auto it : virus) {
            visited[it.first][it.second] = 1;
            q.push({it.first, it.second});
        }

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];
                if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
                if (visited[ny][nx]) continue;
                if (mp[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 0 && !visited[i][j]) cnt++;
            }
        }
        rst = max(rst, cnt);

        return;
    }
    int i = y;
    int j = x;
    for (; i < n; ++i) {
        for (; j < m; ++j) {
            if (mp[i][j] != 0) continue;
            mp[i][j] = 1;
            dfs(i, j + 1, c + 1);
            mp[i][j] = 0;
        }
        j = 0;
    }
} 

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == 2) virus.push_back({i, j});
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] != 0) continue;
            mp[i][j] = 1;
            dfs(i, j + 1, 1);
            mp[i][j] = 0;
        }

    cout << rst << "\n";
    return 0;
}