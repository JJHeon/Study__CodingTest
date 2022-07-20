#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int v, e;

    cin >> v >> e;
    vector<vector<pair<int, int>>> map(v + 1, vector<pair<int, int>>());

    for (int i = 0; i < e; ++i) {
        int a, b, d;
        cin >> a >> b >> d;

        map[a].push_back(make_pair(b, d));
    }

    int minimum = INT32_MAX;
    for (int node = 1; node <= v; ++node) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(v + 1, false);

        for (auto adj = map[node].begin(); adj != map[node].end(); ++adj) {
            auto [n, d] = *adj;

            pq.push(make_pair(d, n));
        }

        while (!pq.empty()) {
            auto [dist, next] = pq.top();
            pq.pop();
            if (next == node) {
                minimum = min(minimum, dist);
                break;
            }
            if(visited[next]) continue;

            visited[next] = true;

            for (auto adj = map[next].begin(); adj != map[next].end(); ++adj) {
                auto [n, d] = *adj;

                pq.push(make_pair(dist + d, n));
            }
        }
    }

    if (minimum == INT32_MAX) {
        cout << "-1\n";
        return 0;
    }
    cout << minimum << "\n";

    return 0;
}