#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, M, V;
vector<vector<int>> li;
vector<bool> visited;

void Recursive(int v) {
    visited[v] = true;

    cout << v << " ";
    for (int i = 0; i < li[v].size(); ++i) {
        int n = li[v][i];
        if (visited[n]) continue;

        Recursive(n);
    }
}

int main() {
    cin >> N >> M >> V;

    li.resize(N + 1, vector<int>());
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int in1, in2;
        cin >> in1 >> in2;

        li[in1].push_back(in2);
        li[in2].push_back(in1);
    }
    for (int i = 1; i < N + 1; ++i) sort(li[i].begin(), li[i].end());

    // for (int i = 0; i < N + 1; ++i) {
    //     for (int k = 0; k < li[i].size(); ++k) cout << li[i][k] << " ";
    //     cout << endl;
    // }

    Recursive(V);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    queue<int> q;
    q.push(V);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        if (visited[v]) continue;
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < li[v].size(); ++i) {
            int n = li[v][i];

            q.push(n);
        }
    }
    cout << endl;

    return 0;
}