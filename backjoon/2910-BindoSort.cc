#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
int mp[1002];
int visited[1002];
vector<pair<int, int>> v;

int dfs(int x) {
    visited[x] = 1;
    int cnt = 1;
    for (int i = x + 1; i < n; ++i) {
        if (visited[i] || mp[x] != mp[i]) continue;

        cnt += dfs(i);
    }
    return cnt;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) cin >> mp[i];

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        int urst = dfs(i);
        v.push_back({mp[i], urst});
    }

    stable_sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
        return a.second > b.second;
    });

    for (auto p : v) {
        for (int i = 0; i < p.second; i++) {
            cout << p.first << " ";
        }
    }
    return 0;
}