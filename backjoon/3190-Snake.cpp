#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

#include <vector>

#include <deque>

using namespace std;

int n, k, w, l, y, x, t, aft, vt;

char dir;

int mp[102][102];

int dy[4] = {-1, 0, 1, 0};

int dx[4] = {0, 1, 0, -1};

deque<pair<int, int>> dq;

vector<pair<int, int>> v;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> y >> x;
        mp[y - 1][x - 1] = -1;
    }

    cin >> l;
    for (int i = 0; i < l; ++i) {
        cin >> aft >> dir;
        v.push_back({aft, dir});
    }

    w = 1;
    y = 0;
    x = 0;
    dq.push_back({y, x});
    mp[0][0] = 1;

    while (true) {
        t++;

        y = dq.back().first;
        x = dq.back().second;

        int ny = y + dy[w];
        int nx = x + dx[w];

        if (ny < 0 || n <= ny || nx < 0 || n <= nx) break;
        if (mp[ny][nx] == 1) break;

        dq.push_back({ny, nx});

        if (mp[ny][nx] == -1)
            mp[ny][nx] = 1;
        else {
            mp[ny][nx] = 1;
            auto [i, j] = dq.front();
            mp[i][j] = 0;
            dq.pop_front();
        }

        if (v.size() > vt) {
            aft = v[vt].first;
            dir = v[vt].second;
            if (aft == t) {
                switch (dir) {
                    case 'D':
                        w = (w + 1) % 4;
                        break;

                    case 'L':
                        w = (w + 3) % 4;
                        break;
                }
                vt++;
            }
        }

        // cout << t << "\n";
        // for(int i = 0; i < n; i++) {
        // 	for(int j = 0; j < n; ++j) cout << mp[i][j] << " ";
        // 	cout << "\n";
        // }
        // cout <<"\n\n";
    }
    cout << t;

    return 0;
}