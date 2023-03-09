#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rst;
int mp[1000002];
int a[1000002];
int x;
int y;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
        a[mp[i]] = 1;
    }

    cin >> x;
    for (int i = 0; i < n; ++i) {
        if (mp[i] >= x) continue;
        int y = abs(mp[i] - x);
        if (mp[i] == y) continue;
        if (a[y]) {
            rst++;
            a[mp[i]] = 0;
        }
    }

    cout << rst;
    return 0;
}