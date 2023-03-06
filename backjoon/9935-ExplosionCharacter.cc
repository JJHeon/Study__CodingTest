#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string s;
string ex;
unordered_map<char, int> map;
string stk;

int main() {
    cin >> s;
    cin >> ex;
    for (int i = 0; i < ex.length(); i++) map.insert({ex[i], i + 1});

    int cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];

        if (map.find(c) != map.end())
            cnt = map[c];
        else
            cnt = 0;

        stk.push_back(s[i]);

        if (cnt == (int)ex.length()) {
            while (((int)stk.length() - (int)ex.length()) >= 0 && stk.substr(stk.length() - ex.length(), ex.length()) == ex) {
                // cout << stk << "\n";
                stk.erase(stk.begin() + (stk.length() - ex.length()), stk.end());
            }
        }
    }

    if (stk.length() == 0) stk = "FRULA";
    cout << stk;

    return 0;
}
