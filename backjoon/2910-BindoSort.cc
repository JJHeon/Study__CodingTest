#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
int ap[1002];
vector<pair<int, int>> v;
map<int, int> mp, mp_ix;
int input;
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        mp[input]++;
        if (mp_ix[input] == 0) mp_ix[input] = i + 1;
    }
    for (auto p : mp) {
        v.push_back({p.second, p.first});
    }
    sort(v.begin(), v.end(), [](auto pa, auto pb) -> bool {
        if (pa.first == pb.first) {
            return mp_ix[pa.second] < mp_ix[pb.second];
        }
        return pa.first > pb.first;
    });

    for (auto p : v) {
        for (int i = 0; i < p.first; i++) {
            cout << p.second << " ";
        }
    }
    return 0;
}