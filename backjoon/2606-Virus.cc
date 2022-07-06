#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<bool> visited;
int main() {
    cin >> N >> M;
    map.resize(N + 1, vector<int>());
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int in1, in2;
        cin >> in1 >> in2;

        map[in1].push_back(in2);
        map[in2].push_back(in1);
    }

    int count = 0;
    queue<int> q;

    q.push(1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) continue;

        visited[v] = true;
        count++;
        for (int i = 0; i < map[v].size(); ++i) {
            int n = map[v][i];
            q.push(n);
        }
    }
    cout << count - 1 << endl;
}