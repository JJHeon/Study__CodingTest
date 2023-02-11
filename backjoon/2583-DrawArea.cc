#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[102][102];
int map[102][102];
vector<int> rst;
int m, n, k;
int sy, sx, ex, ey;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
constexpr int SQ = -1;

int dfs(int y, int x) {
    visited[y][x] = 1;

    int cnt = 1;
    for (int w = 0; w < 4; ++w) {
        int ny = y + dy[w];
        int nx = x + dx[w];

        if (ny < 0 || m <= ny || nx < 0 || n <= nx) continue;
        if (map[ny][nx] == SQ) continue;
        if (visited[ny][nx]) continue;

        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> sx >> sy >> ex >> ey;
        for (int ii = sy; ii < ey; ++ii)
            for (int jj = sx; jj < ex; ++jj) map[ii][jj] = SQ;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || map[i][j] == SQ) continue;

            rst.push_back(dfs(i, j));
        }
    }
    sort(rst.begin(), rst.end());
    cout << rst.size() << "\n";
    for (auto i : rst) cout << i << " ";
    return 0;
}