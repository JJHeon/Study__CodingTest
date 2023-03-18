#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

struct A {
    int y;
    int x;
    int s;
    int d;
    int z;
};

int mp[102][102];
int convert[5] = {0, 0, 2, 1, 3};
int revers[4] = {1, 3, 2, 4};

int rs, cs;
int r, c, s, d, z, m;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<struct A> v;
int rst;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rs >> cs >> m;
    v.push_back({0, 0, 0, 0, 0});
    for (int i = 0; i < m; ++i) {
        cin >> r >> c >> s >> d >> z;
        v.push_back({r, c, s, d, z});
        mp[r][c] = i + 1;
    }

    // // debug
    // cout << "begin "
    //      << "\n";
    // for (int i = 1; i <= rs; i++) {
    //     for (int j = 1; j <= cs; ++j) cout << mp[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n\n";

    for (int t = 1; t <= cs; ++t) {
        // take fish
        for (int i = 1; i <= rs; ++i) {
            if (mp[i][t]) {
                rst += v[mp[i][t]].z;
                v[mp[i][t]].z = 0;
                mp[i][t] = 0;
                break;
            }
        }

        int nmp[102][102];
        memset(nmp, 0, sizeof(nmp));
        // move fish
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].z) {
                int way = convert[v[i].d];
                int ny = v[i].y + (dy[way] * v[i].s);
                int nx = v[i].x + (dx[way] * v[i].s);

                while (ny < 1 || rs < ny) {
                    if (ny < 1) {
                        ny = ((ny - 1) * -1) + 1;
                    } else if (rs < ny)
                        ny = ((rs - (ny - rs)));
                    way = (way + 2) % 4;
                }
                while (nx < 1 || cs < nx) {
                    if (nx < 1) {
                        nx = ((nx - 1) * -1) + 1;
                    } else if (cs < nx)
                        nx = ((cs - (nx - cs)));
                    way = (way + 2) % 4;
                }

                v[i].d = revers[way];
                v[i].y = ny;
                v[i].x = nx;

                if (nmp[ny][nx] > 0) {
                    if (v[i].z > v[nmp[ny][nx]].z) {
                        v[nmp[ny][nx]].z = 0;
                    } else {
                        v[i].z = 0;
                        continue;
                    }
                }
                nmp[ny][nx] = i;
            }
        }

        memcpy(mp, nmp, sizeof(mp));

        // // debug
        // cout << "낚 : " << t << "\n";
        // for (int i = 1; i <= rs; i++) {
        //     for (int j = 1; j <= cs; ++j) cout << mp[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }
    cout << rst;
    return 0;
}