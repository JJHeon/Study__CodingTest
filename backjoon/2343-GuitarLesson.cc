#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

long long m, n, rst = INT64_MAX, l, h, mid;
long long a[100002];
int tmp;

bool check(long long mid) {
    int num = 0;

    long long b = 0;
    long long e = 1;
    while (true) {
        while (e <= n && a[e] - a[b] <= mid) e++;
        b = e - 1;
        num++;

        if (e > n || num > m) break;
    }
    return num <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        a[i] = a[i - 1] + tmp;
    }

    l = 1;
    h = a[n];
    while (l <= h) {
        mid = (l + h) / 2;
        if (check(mid)) {
            rst = min(rst, mid);
            h = mid - 1;
        } else
            l = mid + 1;
    }

    cout << rst;
    return 0;
}