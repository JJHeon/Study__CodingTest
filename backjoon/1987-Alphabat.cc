#include <iostream>
#include <algorithm>

using namespace std;

int r, c;
int A[200];
char mp[22][22];
int rst;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int cnt) {
    rst = max(rst, cnt);

    for (int w = 0; w < 4; ++w) {
        int ny = y + dy[w];
        int nx = x + dx[w];
        if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
        if (A[mp[ny][nx]]) continue;

        A[mp[ny][nx]] = 1;
        dfs(ny, nx, cnt + 1);
        A[mp[ny][nx]] = 0;
    }
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) cin >> mp[i][j];

    A[mp[0][0]] = 1;
    dfs(0, 0, 0);
    cout << rst + 1;
    return 0;
}