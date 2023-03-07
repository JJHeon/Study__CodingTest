#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int rst;

int main() {
    cin >> n;
    int dl, tt;

    for (int i = 0; i < n; ++i) {
        cin >> dl >> tt;
        v.push_back({dl, tt});
    }

    sort(v.begin(), v.end());
    int ct;
    int idx = 0;
    for (ct = 1; ct <= 100000000;) {
        if (idx == v.size()) break;
        if (ct >= v[idx].first)
            ct += v[idx++].second;
        else
            ct++;
    }
    rst = ct;
    cout << rst;

    return 0;
}