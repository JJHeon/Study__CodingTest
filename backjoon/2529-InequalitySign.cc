#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int k;
char oper[10];
int visit[10];
string s;
string rstmn = "9999999999";
string rstmx = "0";

bool check(char a, char b, char op) {
    if (op == '>')
        return a > b;
    else
        return a < b;
}

void dfs(int cnt) {
    if (cnt == k + 1) {
        bool success = true;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (!check(s[i], s[i + 1], oper[i])) {
                success = false;
                break;
            }
        }
        if (success) {
            rstmx = atoll(s.c_str()) > atoll(rstmx.c_str()) ? s : rstmx;
            rstmn = atoll(s.c_str()) < atoll(rstmn.c_str()) ? s : rstmn;
        }

        return;
    }

    for (int i = 0; i <= 9; ++i) {
        if (visit[i]) continue;

        visit[i] = 1;
        s.push_back('0' + i);
        dfs(cnt + 1);
        visit[i] = 0;
        s.pop_back();
    }
}

int main() {
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> oper[i];

    dfs(0);

    cout << rstmx << "\n"
         << rstmn << "\n";

    return 0;
}