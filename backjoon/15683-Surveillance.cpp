#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <queue>

using namespace std;

struct C {
    int t;
    int y;
    int x;
};

int n,
    m;

vector<struct C> v;
int rst = INT32_MAX;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void rol(int y, int x, int w, vector<vector<int>>& mp) {
    int ny = y;
    int nx = x;
    while (true) {
        ny = ny + dy[w];
        nx = nx + dx[w];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) break;
        if (mp[ny][nx] == 6) break;

        if (mp[ny][nx] == 0) mp[ny][nx] = -1;
    }
}

void pick(struct C data, int way, vector<vector<int>>& mp) {
    int y = data.y;
    int x = data.x;
    int t = data.t;

    switch (t) {
        case 1:
            rol(y, x, way, mp);
            break;
        case 2:
            rol(y, x, way, mp);
            rol(y, x, (way + 2) % 4, mp);
            break;
        case 3:
            rol(y, x, way, mp);
            rol(y, x, (way + 1) % 4, mp);
            break;
        case 4:
            rol(y, x, way, mp);
            rol(y, x, (way + 1) % 4, mp);
            rol(y, x, (way + 3) % 4, mp);
            break;
        case 5:
            rol(y, x, way, mp);
            rol(y, x, (way + 1) % 4, mp);
            rol(y, x, (way + 2) % 4, mp);
            rol(y, x, (way + 3) % 4, mp);
            break;
        default:
            break;
    }
}

void dfs(int cnt, vector<vector<int>> cdmp) {
    if (cnt == v.size()) {
        int sakac = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (cdmp[i][j] == 0) sakac++;

        rst = min(sakac, rst);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> nmp(cdmp.begin(), cdmp.end());

        pick(v[cnt], i, nmp);
        dfs(cnt + 1, nmp);
    }
}

int main() {
    cin >> n >> m;

    vector<vector<int>> mp(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
            if (0 < mp[i][j] && mp[i][j] < 6) v.push_back({mp[i][j], i, j});
        }

    dfs(0, mp);

    cout << rst;
    return 0;
}