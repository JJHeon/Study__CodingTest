#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

int k;
char oper[10];
int visit[10];
string s;
string rstmn = "9999999999";
string rstmx = "0";
vector<string> rst;

bool check(char a, char b, char op) {
    if (op == '>')
        return a > b;
    else
        return a < b;
}

void dfs(int cnt) {
    if (cnt == k + 1) {
        rst.push_back(s);
        return;
    }

    for (int i = 0; i <= 9; ++i) {
        if (visit[i]) continue;
        if (cnt == 0 || check(s[cnt - 1], i + '0', oper[cnt - 1])) {
            visit[i] = 1;
            s.push_back('0' + i);

            dfs(cnt + 1);

            visit[i] = 0;
            s.pop_back();
        }
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> oper[i];

    dfs(0);

    sort(rst.begin(), rst.end());
    cout << rst[rst.size() - 1] << "\n";
    cout << rst[0] << "\n";
    return 0;
}