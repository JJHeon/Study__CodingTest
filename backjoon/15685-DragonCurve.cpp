#include <iostream>
#include <vector>

using namespace std;

struct A {
    int x;
    int y;
    int d;
    int g;
};

vector<struct A> in;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int n;
int rst;
int mp[104][104];

int main() {
    cin >> n;
    in.resize(n);
    for (int i = 0; i < n; ++i) cin >> in[i].x >> in[i].y >> in[i].d >> in[i].g;

    int dbg = 1;
    for (auto it : in) {
        int y = it.y;
        int x = it.x;
        int g = it.g;
        int d = it.d;
        int ny = y + dy[d];
        int nx = x + dx[d];
        int top = 1;

        vector<struct A> v;
        v.push_back({x, y, d, g});
        v.push_back({nx, ny, -1, 0});
        mp[y][x] = 1;
        mp[ny][nx] = 1;
        // if (dbg == 2) {
        //     cout << y << " , " << x << "\n";
        //     cout << ny << " , " << nx << "\n";
        // }

        for (int c = 0; c < g; ++c) {
            for (int cg = top - 1; cg >= 0; cg--) {
                int nd = (v[cg].d + 1) % 4;
                ny = ny + dy[nd];
                nx = nx + dx[nd];
                v[top++].d = nd;

                // if (dbg == 2) {
                //     cout << c << ", " << nd << "\n";
                //     cout << ny << ", " << nx << "\n\n";
                // }

                v.push_back({nx, ny, -1, 0});
                mp[ny][nx] = 1;
            }
        }

        // // debug
        // cout << dbg << "\n";
        // dbg++;
        // for (int i = 0; i <= 10; ++i) {
        //     for (int j = 0; j <= 10; ++j) cout << mp[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";
    }

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; ++j)
            if (mp[i][j] && mp[i + 1][j] && mp[i][j + 1] && mp[i + 1][j + 1]) rst++;
    }
    cout << rst;
    return 0;
}