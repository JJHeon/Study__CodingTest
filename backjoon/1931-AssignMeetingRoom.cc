#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int rst = 1;

int main() {
    cin >> n;

    int st, et;

    for (int i = 0; i < n; ++i) {
        cin >> st >> et;
        v.push_back({et, st});
    }

    sort(v.begin(), v.end());

    int from = v[0].second;
    int to = v[0].first;
    for (int i = 1; i < n; ++i) {
        if (v[i].second < to) continue;
        from = v[i].second;
        to = v[i].first;
        rst++;
    }

    cout << rst;

    return 0;
}