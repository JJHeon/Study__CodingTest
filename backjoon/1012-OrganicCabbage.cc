#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int t, m, n, k;
int mp[52][52];
int v[52][52];

int iy, ix;
vector<int> rst;

int main() {
    cin >> t;
    for (int c = 0; c < t; ++c) {
        int cnt = 0;
        queue<pair<int, int>> q;
        fill(&mp[0][0], &mp[0][0] + 52 * 52, 0);
        fill(&v[0][0], &v[0][0] + 52 * 52, 0);

        cin >> m >> n >> k;
        for (int i = 0; i < k; ++i) {
            cin >> ix >> iy;

            mp[iy][ix] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 0) continue;
                if (v[i][j]) continue;

                q.push({i, j});
                v[i][j] = 1;
                cnt += 1;
                while (!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();

                    for (int w = 0; w < 4; ++w) {
                        int ny = y + dy[w];
                        int nx = x + dx[w];

                        if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;
                        if (v[ny][nx]) continue;
                        if (mp[ny][nx] == 0) continue;

                        v[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
        rst.push_back(cnt);
    }
    for (auto r : rst) cout << r << "\n";
    return 0;
}