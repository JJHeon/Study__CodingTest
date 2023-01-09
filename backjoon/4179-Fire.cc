#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdint>
#include <algorithm>

using namespace std;

#define INF INT32_MAX
int r, c;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char map[1001][1001];
int jh[1001][1001];
int fire[1001][1001];
int sy, sx;

int Solution() {
    queue<pair<int, int>> fire_q;
    fill(&fire[0][0], &fire[0][0] + 1001 * 1001, INF);
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'J') {
                sy = i;
                sx = j;
            } else if (map[i][j] == 'F') {
                fire[i][j] = 1;
                fire_q.push({i, j});
            }
        }
    }

    
    while (!fire_q.empty()) {
        auto [y, x] = fire_q.front();
        fire_q.pop();

        for (int way = 0; way < 4; ++way) {
            int ny = y + dy[way];
            int nx = x + dx[way];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (fire[ny][nx] != INF || map[ny][nx] == '#') continue;
            fire[ny][nx] = fire[y][x] + 1;
            fire_q.push({ny, nx});
        }
    }

    queue<pair<int, int>> jh_q;
    jh_q.push({sy, sx});
    jh[sy][sx] = 1;
    while (!jh_q.empty()) {
        auto [y, x] = jh_q.front();
        jh_q.pop();

        if (y == r - 1 || y == 0 || x == c - 1 || x == 0) {
            return jh[y][x];
        }

        for (int w = 0; w < 4; ++w) {
            int ny = y + dy[w];
            int nx = x + dx[w];
            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (map[ny][nx] == '#' || jh[ny][nx] != 0) continue;
            if (jh[y][x] + 1 >= fire[ny][nx]) continue;

            jh[ny][nx] = jh[y][x] + 1;
            jh_q.push({ny, nx});
        }
    }

    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j){
    //         cout << fire[i][j] << " ";
    //     }
    //     cout << "\n\n";
    // }
    // for (int i = 0; i < r; ++i) {
    //     for (int j = 0; j < c; ++j){
    //         cout << jh[i][j] << " ";
    //     }
    //     cout << "\n\n";
    // }

    return -1;
}

int main() {
    int ret = Solution();
    if (ret != -1)
        cout << ret;
    else
        cout << "IMPOSSIBLE";

    return 0;
}