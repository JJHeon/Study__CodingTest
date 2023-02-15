#include <iostream>
#include <cstdint>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int rst = INT32_MAX;
int tc = 0;
int mp[100002];

void bfs(int n, int k) {
    queue<pair<int, int>> q;
    mp[n] = 1;
    q.push({n, 1});

    while (q.size()) {
        auto [n, c] = q.front();
        q.pop();
        if (rst < c) continue;
        if (n == k) {
            if (c < rst) {
                rst = c;
                tc = 1;
            } else if (c == rst)
                tc += 1;
            continue;
        }

        if (2 * n <= 100000 && mp[2 * n] >= c + 1) {
            mp[2 * n] = c + 1;
            q.push({2 * n, c + 1});
        }
        if (0 <= n - 1 && mp[n - 1] >= c + 1) {
            mp[n - 1] = c + 1;
            q.push({n - 1, c + 1});
        }
        if (n + 1 <= 100000 && mp[n + 1] >= c + 1) {
            mp[n + 1] = c + 1;
            q.push({n + 1, c + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&mp[0], &mp[0] + 100002, INT32_MAX);

    cin >> n >> k;

    bfs(n, k);

    cout << rst - 1 << "\n";
    cout << tc << "\n";
    return 0;
}