#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;
int rst;

int main() {
    // Write C++ code here
    cin >> n;
    for (int i = 0; i < n; i++) {
        int dl, cup;
        cin >> dl >> cup;
        v.push_back({dl, cup});
    }

    sort(v.begin(), v.end());

    for (auto it : v) {
        pq.push(it.second);
        if (it.first < pq.size()) pq.pop();
    }

    while (pq.size()) {
        rst += pq.top();
        pq.pop();
    }
    cout << rst;
    return 0;
}
