#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string s;
vector<string> rst;

int main() {
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        stack<char> stk;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']') {
                if (stk.size() && stk.top() == '(' && s[i] == ')')
                    stk.pop();
                else if (stk.size() && stk.top() == '[' && s[i] == ']')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }

        if (stk.size())
            rst.push_back("no");
        else
            rst.push_back("yes");
    }

    for (auto it : rst) cout << it << "\n";
    return 0;
}
