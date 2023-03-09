#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int t, r, c, rst;
int tt;
int mp[52][52];
int tmp[52][52];
int visit[52][52];
int y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef struct a_ {
    int y;
    int x;
} a;
vector<a> v;

int main() {
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] == -1) v.push_back({i, j});
        }

    while (tt < t) {
        memset(tmp, 0, sizeof(tmp));
        tmp[v[0].y][v[0].x] = -1;
        tmp[v[1].y][v[1].x] = -1;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (mp[i][j] == -1 || mp[i][j] == 0) continue;
                int cnt = 0;
                for (int w = 0; w < 4; ++w) {
                    int ny = i + dy[w];
                    int nx = j + dx[w];

                    if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
                    if (mp[ny][nx] == -1) continue;

                    tmp[ny][nx] += (mp[i][j] / 5);
                    cnt++;
                }
                tmp[i][j] += (mp[i][j] - (mp[i][j] / 5 * cnt));
            }

        y = v[0].y - 1;
        x = v[0].x;
        tmp[y][x] = 0;
        for (; y - 1 >= 0; --y) tmp[y][x] = tmp[y - 1][x];
        for (; x + 1 < c; ++x) tmp[y][x] = tmp[y][x + 1];
        for (; y + 1 <= v[0].y; ++y) tmp[y][x] = tmp[y + 1][x];
        for (; x - 1 > 0; --x) tmp[y][x] = tmp[y][x - 1];
        tmp[y][x] = 0;

        y = v[1].y + 1;
        x = v[1].x;
        tmp[y][x] = 0;
        for (; y + 1 < r; ++y) tmp[y][x] = tmp[y + 1][x];
        for (; x + 1 < c; ++x) tmp[y][x] = tmp[y][x + 1];
        for (; y - 1 >= v[1].y; --y) tmp[y][x] = tmp[y - 1][x];
        for (; x - 1 > 0; --x) tmp[y][x] = tmp[y][x - 1];
        tmp[y][x] = 0;

        memcpy(mp, tmp, sizeof(mp));
        tt++;
        // //debug
        // cout << tt << "\n";
        // for(int i = 0; i < r; i++) {
        // 	for(int j  = 0; j < c; ++j) cout << tmp[i][j] << "  ";
        // 	cout <<"\n";
        // }
        // cout<<"\n\n";
    }

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            if (mp[i][j] != -1) rst += mp[i][j];
        }

    cout << rst;
    return 0;
}