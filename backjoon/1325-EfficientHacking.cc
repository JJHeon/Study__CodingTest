#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[10002];
int visited[10002];
vector<int> rst;

int a, b;
int mn;

int dfs(int idx, int visited[100002]) {
    visited[idx] = 1;
    int cnt = 1;

    for (auto it : adj[idx]) {
        if (visited[it]) continue;
        cnt += dfs(it, visited);
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        fill(&visited[0], &visited[0] + 10002, 0);
        sum = dfs(i, visited);

        if (sum > mn) {
            mn = sum;
            rst.clear();
            rst.push_back(i);
        } else if (sum == mn)
            rst.push_back(i);
    }

    sort(rst.begin(), rst.end());
    for (auto val : rst) cout << val << " ";
    return 0;
}