#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string s;
int n;
vector<string> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int st = -1, en = s.length();
        for (int j = 0; j < s.length(); ++j) {
            char c = s[j];
            if (st == -1 && '0' <= c && c <= '9') {
                st = j;
            } else if (st != -1 && 'a' <= c && c <= 'z') {
                en = j;

                v.push_back(s.substr(st, en - st));
                st = -1;
                en = s.length();
            }
        }

        if (st != -1) {
            v.push_back(s.substr(st, en - st));
        }
    }

    for (auto& ss : v) {
        int st = -1, en = 1;
        if(ss[0] != '0') continue;
        for (int i = 0; i < ss.length(); ++i) {
            char c = ss[i];
            if (st == -1 && '0' == c) {
                st = i;
            } else if (st != -1 && '1' <= c && c <= '9') {
                en = i;
                ss.erase(ss.begin() + st, ss.begin() + en);
                st = -1;
                break;
            }
        }
        if (st != -1) {
            ss = "0";
        }
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) -> bool {
        if (a.length() != b.length()) return a.length() < b.length();

        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return true;
    });
    for (auto val : v) cout << val << "\n";

    return 0;
}