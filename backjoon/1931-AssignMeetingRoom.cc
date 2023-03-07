#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int n;

vector<pair<int, int>> v;

vector<pair<int, int>> ans;

int main() {
    cin >> n;

    int st, et;

    for (int i = 0; i < n; ++i) {
        cin >> st >> et;
        v.push_back({st, et});
    }

    sort(v.begin(), v.end());

    ans.push_back(v[0]);

    for (int i = 1; i < v.size(); ++i) {
        if (ans[ans.size() - 1].second > v[i].second) {
            ans.pop_back();
            ans.push_back(v[i]);
        } else if (ans[ans.size() - 1].second <= v[i].first)
            ans.push_back(v[i]);
    }

    cout << ans.size();

    return 0;
}