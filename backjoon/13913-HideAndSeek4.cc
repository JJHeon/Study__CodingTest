#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdint>

using namespace std;

int n, k;
int mp[100002];
int pv[100002];
int rst = INT32_MAX;

void bfs(int n, int k) {
    queue<pair<int, int>> q;
    mp[n] = 1;

    q.push({n, 1});

    pv[n] = -1;

    while (q.size()) {
        auto [n, c] = q.front();
        q.pop();

        if (rst < c) continue;
        if (n == k) {
            rst = c;

            stack<int> stk;
            stk.push(n);

            int i = pv[n];
            while (i != -1) {
                stk.push(i);

                i = pv[i];
            }

            cout << rst - 1 << "\n";
            while (stk.size()) {
                cout << stk.top() << " ";
                stk.pop();
            }
            break;
        }

        if (n * 2 <= 100000 && c + 1 < mp[2 * n]) {
            mp[2 * n] = c + 1;
            pv[2 * n] = n;

            q.push({2 * n, c + 1});
        }

        if (n + 1 <= 100000 && c + 1 < mp[n + 1]) {
            mp[n + 1] = c + 1;
            pv[n + 1] = n;

            q.push({n + 1, c + 1});
        }

        if (n - 1 >= 0 && c + 1 < mp[n - 1]) {
            mp[n - 1] = c + 1;
            pv[n - 1] = n;

            q.push({n - 1, c + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    fill(&mp[0], &mp[0] + 100002, INT32_MAX);
    fill(&pv[0], &pv[0] + 100002, -1);

    bfs(n, k);

    return 0;
}