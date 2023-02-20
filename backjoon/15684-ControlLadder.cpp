#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int n, m, h;
int mp[50][50];
vector<pair<int, int>> line;
int rst = INT32_MAX;

void dfs(int cnt, int next) {
    bool success = true;

    for (int j = 1; j <= n; ++j) {
        int se = j;
        for (int i = 1; i <= h; ++i) {
            if (mp[i][se])
                se++;
            else if (mp[i][se - 1])
                se--;
            if (se < 1 || n < se) {
                success = false;
                break;
            }
        }

        if (!success) break;
        if (se != j) {
            success = false;

            break;
        }
    }

    if (success) rst = min(rst, cnt);

    if (cnt == 3) return;

    for (int i = next; i < line.size(); ++i) {
        int ny = line[i].first;
        int nx = line[i].second;

        if (mp[ny][nx - 1] || mp[ny][nx + 1] || mp[ny][nx]) continue;

        mp[ny][nx] = 1;
        dfs(cnt + 1, next + 1);
        mp[ny][nx] = 0;
    }
}

int main(int argc, char* argv[]) {
    cin >> n >> m >> h;

    for (int i = 0; i < m; ++i) {
        int y, x;
        cin >> y >> x;
        mp[y][x] = 1;
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= n - 1; ++j) {
            if (mp[i][j] || mp[i][j - 1] || mp[i][j + 1]) continue;

            line.push_back({i, j});
        }
    }

    dfs(0, 0);

    if (rst == INT32_MAX)
        cout << "-1\n";
    else
        cout << rst;

    return 0;
}