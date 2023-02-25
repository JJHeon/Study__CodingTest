#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int t, n, m, a, b;
int mp[1002][1002];
int node[1002];
vector<string> anw;

void dfs(int s, int prev, bool& keep) {
    node[s] = 1;
    for (int i = 1; i <= n; ++i) {
        if (!mp[s][i] || prev == i) continue;
        if (i != s && node[i]) {
            keep = false;
            continue;
        }
        dfs(i, s, keep);
    }
}

int main() {
    cin >> t;
    for (int k = 0; k < t; ++k) {
        bool keep = true;
        memset(mp, 0, sizeof(mp));
        memset(node, 0, sizeof(node));

        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            mp[a][b] += 1;
            mp[b][a] += 1;

            if (mp[a][b] > 1 || mp[b][a] > 1) {
                keep = false;
            }
        }

        if (!keep) {
            anw.push_back("graph");
            continue;
        }
        // cout << n;
        dfs(1, -1, keep);

        if (!keep) {
            anw.push_back("graph");
            continue;
        }

        for (int j = 1; j <= n; ++j)
            if (!node[j]) {
                keep = false;
                break;
            }

        if (!keep) {
            anw.push_back("graph");
            continue;
        }

        anw.push_back("tree");
    }
    for (auto it : anw) cout << it << "\n";
    return 0;
}