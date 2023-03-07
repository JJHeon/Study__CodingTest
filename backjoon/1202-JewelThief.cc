#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
int m, v, c, t;
priority_queue<int> pq;
vector<pair<int, int>> in;
vector<int> bp;
long long rst;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        in.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bp.push_back(c);
    }
    sort(in.begin(), in.end());
    sort(bp.begin(), bp.end());

    for (int b = 0; b < k; b++) {
        while (t != in.size() && in[t].first <= bp[b]) {
            pq.push(in[t].second);
            t++;
        }

        if (pq.size()) {
            rst += pq.top();
            pq.pop();
        }
    }
    cout << rst;
    return 0;
}