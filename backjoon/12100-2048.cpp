#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int rst;

void rotate(int way, vector<vector<int>>& mm) {
    for (int w = 0; w < way; ++w) {
        auto nm = mm;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nm[n - 1 - j][i] = mm[i][j];
            }
        }
        mm = nm;
    }
}
void sum(vector<vector<int>>& vm) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (vm[i][k] != 0 && vm[i][k] != vm[i][j]) break;
                if (vm[i][j] == vm[i][k]) {
                    vm[i][j] += vm[i][k];
                    vm[i][k] = 0;
                    break;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            if (vm[i][j] != 0) {
                int t = -1;
                for (int k = j - 1; k >= 0; k--) {
                    if (vm[i][k] == 0) t = k;
                }
                if (t != -1) {
                    vm[i][t] = vm[i][j];
                    vm[i][j] = 0;
                }
            }
        }
    }
}

void dfs(int cnt, vector<vector<int>> mp) {
    if (cnt == 5) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) rst = max(rst, mp[i][j]);

        return;
    }

    for (int i = 0; i < 5; ++i) {
        vector<vector<int>> vm(mp);

        if (i != 0) {
            rotate(i, vm);
            sum(vm);
            rotate(4 - i, vm);
        }

        // cout << cnt << ", " << i << "\n";
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) cout << vm[i][j] << " ";
        //     cout << "\n";
        // }
        // cout << "\n\n";

        dfs(cnt + 1, vm);
    }
}

int main() {
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> v[i][j];

    dfs(0, v);

    cout << rst;

    return 0;
}