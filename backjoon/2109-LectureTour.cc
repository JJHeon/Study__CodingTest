#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int rst;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;

    int p, d;
    for (int i = 0; i < n; ++i) {
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        pq.push(it.second);
        if (pq.size() > it.first) pq.pop();
    }

    while (pq.size()) {
        rst += pq.top();
        pq.pop();
    }
    cout << rst;

    return 0;
}