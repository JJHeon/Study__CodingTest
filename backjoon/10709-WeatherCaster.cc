#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;
int h, w;
char mp[102][102];
queue<tuple<int, int, int>> q;
int rst[102][102];

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            scanf(" %1c", &mp[i][j]);
            if (mp[i][j] == 'c') {
                q.push(make_tuple(i, j, 1));
                rst[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();

        int nx = x + 1;
        if (nx >= w) continue;
        if (rst[y][nx] != 0 && rst[y][nx] <= c + 1) continue;
        rst[y][nx] = c + 1;
        q.push(make_tuple(y, nx, c + 1));
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) rst[i][j] += -1;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) printf("%d ", rst[i][j]);
        printf("\n");
    }
    return 0;
}