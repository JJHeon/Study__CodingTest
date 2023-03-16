#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

struct b {
    int rr;
    int cc;
    int ss;
};
int n, m, k;
int a[52][52];
int visit[6];
vector<struct b> v;
int r, c, s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int vmp[52][52];
int rst = INT32_MAX;

void rotate(int r, int c, int s, vector<vector<int>>& bb) {
    memset(vmp, 0, sizeof(vmp));
    for (int i = 0; i < s; ++i) {
        vector<pair<int, int>> vv;
        int rbegin = r - s + i;
        int rend = r + s - i;
        int cbegin = c - s + i;
        int cend = c + s - i;
        int w = 0;

        vv.push_back({rbegin, cbegin});
        vmp[rbegin][cbegin] = 1;

        while (true) {
            auto [y, x] = vv[vv.size() - 1];
            int ny = y + dy[w];
            int nx = x + dx[w];

            if (ny < rbegin || rend < ny || nx < cbegin || cend < nx || vmp[ny][nx]) {
                w += 1;
            }
            if (w == 4) break;
            ny = y + dy[w];
            nx = x + dx[w];
            vmp[ny][nx] = 1;
            vv.push_back({ny, nx});
        }
        int tmp = bb[vv[vv.size() - 1].first][vv[vv.size() - 1].second];
        for (int i = vv.size() - 1; i >= 1; --i)
            bb[vv[i].first][vv[i].second] = bb[vv[i - 1].first][vv[i - 1].second];
        bb[vv[0].first][vv[0].second] = tmp;
    }
}

void dfs(int cnt, vector<vector<int>> aa) {
    if (cnt == v.size()) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum = 0;
            for (int j = 1; j <= m; ++j) sum += aa[i][j];
            rst = min(rst, sum);
        }
        return;
    }

    for (int i = 0; i < v.size(); ++i) {
        if (visit[i]) continue;
        vector<vector<int>> aaa(aa);

        visit[i] = 1;
        rotate(v[i].rr, v[i].cc, v[i].ss, aaa);
        dfs(cnt + 1, aaa);
        visit[i] = 0;
    }
}

int main() {
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }

    for (int i = 0; i < k; ++i) {
        cin >> r >> c >> s;
        v.push_back({r, c, s});
    }
    dfs(0, a);

    cout << rst;
    return 0;
}