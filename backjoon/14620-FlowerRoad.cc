#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int n;
int price[102][102];
int visit[102][102];
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};
int rst = INT32_MAX;

bool check(int y, int x) {
    for (int w = 0; w < 5; ++w) {
        int ny = y + dy[w];
        int nx = x + dx[w];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) return false;
        if (visit[ny][nx]) return false;
    }
    return true;
}

void set(int y, int x) {
    visit[y][x] = 1;
    visit[y - 1][x] = 1;
    visit[y + 1][x] = 1;
    visit[y][x - 1] = 1;
    visit[y][x + 1] = 1;
}

void reset(int y, int x) {
    visit[y][x] = 0;
    visit[y - 1][x] = 0;
    visit[y + 1][x] = 0;
    visit[y][x - 1] = 0;
    visit[y][x + 1] = 0;
}

void dfs(int ny, int nx, int cnt) {
    if (cnt >= 3) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j]) {
                    sum += price[i][j];
                }
            }
        }

        rst = min(rst, sum);

        return;
    }

    int y = ny;
    int x = nx;

    for (; y < n - 1; ++y) {
        for (; x < n - 1; ++x) {
            if (check(y, x))
                set(y, x);
            else
                continue;

            dfs(ny, nx + 1, cnt + 1);
            reset(y, x);
        }

        x = 0;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> price[i][j];

    dfs(0, 0, 0);

    cout << rst;

    return 0;
}