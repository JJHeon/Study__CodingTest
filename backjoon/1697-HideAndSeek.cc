#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <queue>

using namespace std;
int N, K;

int main() {
    cin >> N >> K;
    queue<tuple<int, int>> q;
    vector<int> visited(100001, INT32_MAX);

    q.push(make_tuple(N, 1));
    while (!q.empty()) {
        auto [pos, count] = q.front();
        q.pop();
        if (pos < 0 || pos > 100000) continue;
        if (visited[pos] < count) continue;

        visited[pos] = count;

        if (pos != 0) q.push(make_tuple(pos * 2, count + 1));
        q.push(make_tuple(pos + 1, count + 1));
        q.push(make_tuple(pos - 1, count + 1));
    }
    cout << visited[K] - 1 << "\n";
    for (int i = 0; i < K; ++i) cout << visited[i] << " ";
    cout << endl;

    return 0;
}