#include <iostream>
#include <map>

using namespace std;

int n, m, rst, want;
int a[1004], b[1004];
int aa[2008], bb[2008];
map<int, int> mA, mB;

void func(int until, int li[2008], map<int, int>& m) {
    for (int g = 1; g <= until; ++g) {
        for (int i = g; i < until + g; ++i) {
            m[li[i] - li[i - g]]++;
            if (g == until) break;
        }
    }
}

int main() {
    cin >> want >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        aa[i] = aa[i - 1] + a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        bb[i] = bb[i - 1] + b[i];
    }

    for (int i = m + 1; i <= 2 * m; ++i) aa[i] = aa[i - 1] + a[i - m];
    for (int i = n + 1; i <= 2 * n; ++i) bb[i] = bb[i - 1] + b[i - n];

    func(m, aa, mA);
    func(n, bb, mB);

    rst = mA[want] + mB[want];
    for (int i = 1; i < want; ++i) rst += (mA[want - i] * mB[i]);

    cout << rst;
    return 0;
}