#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

int rst, n, k;
int mp[102];
int visit[102];
vector<int> v;

int main() {
    cin >> k >> n;
    for (int i = 0; i < n; ++i) cin >> mp[i];

    for (int i = 0; i < n; ++i) {
        if (!visit[mp[i]]) {
            if (v.size() == k) {
                int idx = 0, pos;
                for (auto it : v) {
                    int pick = INT32_MAX;
                    for (int j = i + 1; j < n; ++j) {
                        if (it == mp[j]) {
                            pick = j;
                            break;
                        }
                    }
                    if (idx < pick) {
                        idx = pick;
                        pos = it;
                    }
                }
                visit[pos] = 0;
                rst++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(mp[i]);
            visit[mp[i]] = 1;
        }
    }

    cout << rst;
    return 0;
}