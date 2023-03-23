#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

long long n, m;
vector<long long> jewel;
long long h, l, mid;
long long rst = INT64_MAX;

bool check(long long mid) {
    int num = 0;
    for (int i = 0; i < m; ++i) {
        num += jewel[i] / mid;
        if (jewel[i] % mid) num += 1;
    }

    return num <= n;
}

int main() {
    cin >> n >> m;
    jewel.resize(m);
    for (int i = 0; i < m; ++i) cin >> jewel[i], h = max(jewel[i], h);

    l = 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (check(mid)) {
            rst = min(mid, rst);
            h = mid - 1;
        } else
            l = mid + 1;
    }

    cout << rst;
    return 0;
}