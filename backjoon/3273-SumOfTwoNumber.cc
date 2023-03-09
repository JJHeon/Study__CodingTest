#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int rst;
int x;

int main() {
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> x;

    sort(v.begin(), v.end());

    int sp = 0, ep = n - 1;
    while (sp < ep) {
        if (v[sp] + v[ep] == x) {
            ep--;
            rst++;
        } else if (v[sp] + v[ep] > x)
            ep--;
        else if (v[sp] + v[ep] < x)
            sp++;
    }
    cout << rst;

    return 0;
}