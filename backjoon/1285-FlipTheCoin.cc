#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char input;
int mp[22];
int rst = INT32_MAX;

void dfs(int next) {
    if (next == n + 1) {
        int sum = 0;
        for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j)
                if (mp[j] & i) cnt++;
            sum += min(cnt, n - cnt);
        }

        rst = min(rst, sum);
        return;
    }

    mp[next] = ~mp[next];
    dfs(next + 1);
    mp[next] = ~mp[next];
    dfs(next + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int v = 1;
        for (int j = 1; j <= n; ++j) {
            cin >> input;
            if (input == 'T') mp[i] |= v;
            v *= 2;
        }
    }

    dfs(1);

    cout << rst;

    return 0;
}