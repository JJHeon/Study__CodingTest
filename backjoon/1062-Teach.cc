#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
vector<string> strs;
string in;
int rst;
int visit[27];

void func(int h, int cnt, int until) {
    if (cnt == until) {
        int sum = 0;
        // for(int i = 0; i < 26; i++) cout << visit[i] << " ";
        // cout << "\n";
        for (auto s : strs) {
            for (int j = 0; j < s.length(); ++j) {
                if (!visit[s[j] - 'a']) goto out;
            }
            sum++;
        out:
            continue;
        }

        rst = max(rst, sum);
        return;
    }

    for (int i = h; i < 26; ++i) {
        if (visit[i]) continue;
        visit[i] = 1;
        func(i + 1, cnt + 1, until);
        visit[i] = 0;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> in;
        if (in.length() == 8)
            strs.push_back("a");
        else
            strs.push_back(in.substr(4, in.length() - 8));
    }

    visit['a' - 'a'] = 1;
    visit['n' - 'a'] = 1;
    visit['t' - 'a'] = 1;
    visit['i' - 'a'] = 1;
    visit['c' - 'a'] = 1;

    if (k < 5) {
        cout << "0\n";
        return 0;
    }

    func(0, 0, k - 5);
    cout << rst;

    return 0;
}