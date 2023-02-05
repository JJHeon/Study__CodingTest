#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int rst = 0;
;
int N;
int cnt;
int map[102][102];
int visited[102][102];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int d) {
    visited[y][x] = 1;
    for (int w = 0; w < 4; ++w) {
        int ny = y + dy[w];
        int nx = x + dx[w];
        if (ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] <= d) continue;
        dfs(ny, nx, d);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> map[i][j];

    for (int h = 0; h < 100; ++h) {
        fill(&visited[0][0], &visited[0][0] + 102 * 102, 0);
        cnt = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (visited[i][j] != 0 || map[i][j] <= h) continue;
                cnt++;
                dfs(i, j, h);
            }
        }

        rst = max(rst, cnt);
    }

    cout << rst << "\n";
    return 0;
}