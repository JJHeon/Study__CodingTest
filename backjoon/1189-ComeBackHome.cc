#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int r, c;
int k;
char mp[10][10];
int visit[10][10];
int rst;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
    if (k < c) return;
    if (y == 0 && x == c - 1 && cnt == k) {
        rst += 1;
        return;
    }

    for (int w = 0; w < 4; ++w) {
        int ny = y + dy[w];
        int nx = x + dx[w];

        if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
        if (visit[ny][nx]) continue;
        if (mp[ny][nx] == 'T') continue;

        visit[ny][nx] = 1;
        dfs(ny, nx, cnt + 1);
        visit[ny][nx] = 0;
    }
}

int main() {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; ++j)
            cin >> mp[i][j];

    visit[r - 1][0] = 1;
    dfs(r - 1, 0, 1);
    cout << rst;
    return 0;
}