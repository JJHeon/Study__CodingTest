#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

int n, m;
string mp[302];
int visit[302][302];
int x1, y1, x2, y2;
int t;
vector<pair<int, int>> v;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void sol() {
    while (true) {
        t += 1;
        memset(visit, 0, sizeof(visit));
        v.clear();
        queue<pair<int, int>> q;

        q.push({y1 - 1, x1 - 1});
        visit[y1 - 1][x1 - 1] = 1;

        while (q.size()) {
            auto [y, x] = q.front();
            q.pop();

            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];

                if (ny < 0 || n <= ny || nx < 0 || m <= nx || visit[ny][nx]) continue;
                if (mp[ny][nx] == '#') {
                    // success
                    cout << t << "\n";
                    return;
                }

                if (mp[ny][nx] == '1') {
                    v.push_back({ny, nx});
                }

                else {
                    q.push({ny, nx});
                    visit[ny][nx] = 1;
                }
            }
        }

        for (auto it : v) mp[it.first][it.second] = '0';
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;

    cin >> y1 >> x1 >> y2 >> x2;

    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
    }

    if (y1 == y2 && x2 == x1) {
        cout << "0\n";

        return 0;
    }

    sol();

    return 0;
}