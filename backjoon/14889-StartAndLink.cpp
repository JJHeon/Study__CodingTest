#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using namespace std;

int n;
int mp[22][22];
int rst = INT32_MAX;
int visit[22];

void dfs(int cnt, int idx) {
    if (cnt == n / 2) {
        vector<int> st;
        vector<int> li;
        for (int i = 0; i < n; ++i) {
            if (visit[i])
                st.push_back(i);
            else
                li.push_back(i);
        }

        int start = 0;
        int link = 0;
        for (int i = 0; i < st.size(); ++i)
            for (int j = i + 1; j < st.size(); ++j) {
                // cout << "start i : " << st[i] << " , " << st[j] << "\n";
                start += mp[st[i]][st[j]];
                start += mp[st[j]][st[i]];
            }

        for (int i = 0; i < li.size(); ++i)
            for (int j = i + 1; j < li.size(); ++j) {
                // cout << "link i : " << li[i] << " , " << li[j] << "\n";
                link += mp[li[i]][li[j]];
                link += mp[li[j]][li[i]];
            }

        rst = min(rst, abs(start - link));

        return;
    }
    for (int i = idx; i < n; ++i) {
        visit[i] = 1;
        dfs(cnt + 1, i + 1);
        visit[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> mp[i][j];

    dfs(0, 0);

    if (rst != INT32_MAX)
        cout << rst;
    else
        cout << "0";
    return 0;
}