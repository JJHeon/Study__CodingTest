#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int t;
string s;
vector<string> rst;

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> s;

        stack<int> stk;
        for (int j = 0; j < s.length(); ++j) {
            if (stk.size() && s[j] == ')' && stk.top() == '(')
                stk.pop();
            else
                stk.push(s[j]);
        }

        if (stk.size())
            rst.push_back("NO");
        else
            rst.push_back("YES");
        
    }

    for (auto str : rst) cout << str << "\n";
    return 0;
}