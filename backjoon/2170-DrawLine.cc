#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, y, x, sp, ep, nsp, nep;
long long rst;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    sp = v[0].first;
    ep = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        nsp = v[i].first;
        nep = v[i].second;

        if (nsp <= ep && ep < nep)
            ep = nep;
        else if (ep < nsp) {
            rst += ((long long)ep - (long long)sp);
            ep = nep;
            sp = nsp;
        }
    }
    rst += ((long long)ep - (long long)sp);
    cout << rst;
    return 0;
}