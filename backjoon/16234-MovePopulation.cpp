#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n, l, r;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int mp[52][52];
int nmp[52][52];
int visited[52][52];
int t;

int dfs(int i, int j, vector<pair<int, int>>& v) {
    int rst = 0;
    for (int w = 0; w < 4; ++w) {
        int ny = i + dy[w];
        int nx = j + dx[w];
        if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
        if (visited[ny][nx]) continue;

        int diff = abs(mp[ny][nx] - mp[i][j]);
        if (diff < l || r < diff) continue;

        visited[ny][nx] = 1;
        v.push_back({ny, nx});
        rst += mp[ny][nx];
        rst += dfs(ny, nx, v);
    }
    return rst;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mp[i][j];

    memcpy(nmp, mp, sizeof(mp));
    while (true) {
        memcpy(mp, nmp, sizeof(mp));
        memset(&visited[0][0], 0, sizeof(visited));
        bool find = false;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                vector<pair<int, int>> v;
                int sum = dfs(i, j, v);

                if (v.size() > 1) {
                    find = true;
                    int avrg = sum / v.size();
                    for (auto it : v) nmp[it.first][it.second] = avrg;
                }
            }
        }

        if (!find) break;
        t++;
    }

    cout << t;
    return 0;
}