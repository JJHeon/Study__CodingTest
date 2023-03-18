#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int n;
int a[102];
int oper[4];
long long rst_max = INT64_MIN;
long long rst_min = INT64_MAX;

void dfs(int cnt, long long cur) {
    if (cnt == n) {
        rst_max = max(rst_max, cur);
        rst_min = min(rst_min, cur);
        return;
    }
    // cout << cnt << " , " << cur;
    for (int i = 0; i < 4; ++i) {
        if (oper[i]) {
            oper[i]--;

            switch (i) {
                case 0:
                    // cout << "+\n";
                    dfs(cnt + 1, cur + a[cnt]);
                    break;
                case 1:
                    // cout << "-\n";
                    dfs(cnt + 1, cur - a[cnt]);
                    break;
                case 2:
                    // cout << "*\n";
                    dfs(cnt + 1, cur * a[cnt]);
                    break;
                case 3:
                    // cout << "/\n";
                    dfs(cnt + 1, cur / a[cnt]);
                    break;
            }

            oper[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < 4; ++i) cin >> oper[i];

    dfs(1, a[0]);

    cout << rst_max << "\n"
         << rst_min;
    return 0;
}