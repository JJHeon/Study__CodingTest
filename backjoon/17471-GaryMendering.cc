#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdint>
using namespace std;

int n;
vector<int> adj[12];
int mp[12];
int in;
int visit[12];
int a, b;
int rst = INT32_MAX;

void start(int idx, int pick, int visit[12]) {
    visit[idx] = true;
    for (auto it : adj[idx]) {
        if (visit[it]) continue;
        if (pick & (1 << it)) start(it, pick, visit);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> mp[i];

    for (int i = 0; i < n; ++i) {
        cin >> in;
        int v;
        for (int j = 0; j < in; ++j) {
            cin >> v;
            if (v - 1 >= 0) adj[i].push_back(v - 1);
        }
    }

    for (int p = 1; p < (1 << n) - 1; p++) {
        int pick = p;
        int idx = log2(pick & (-1 * pick));
        memset(visit, 0, sizeof(visit));

        start(idx, pick, visit);
        for (int i = 0; i < n; ++i) {
            if (pick & (1 << i) && !visit[i]) goto finish;
        }

        pick = ~pick;
        idx = log2(pick & (-1 * pick));
        memset(visit, 0, sizeof(visit));

        start(idx, pick, visit);
        for (int i = 0; i < n; ++i)
            if (pick & (1 << i) && !visit[i]) goto finish;

        a = 0;
        b = 0;
        for (int i = 0; i < n; ++i) {
            if (pick & (1 << i))
                a += mp[i];
            else
                b += mp[i];
        }

        rst = min(rst, abs(a - b));
    finish:
        continue;
    }

    if (rst != INT32_MAX)
        cout << rst;
    else
        cout << "-1";

    return 0;
}