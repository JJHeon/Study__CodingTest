#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int n;
int mp[200001];
string s;
stack<int> stk;
int t = 1;
int rst;

int main() {
    cin >> n;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(')
            stk.push(t++);
        else if (stk.size() == 0 && s[i] == ')') {
            t += 1;
        } else if (s[i] == ')') {
            mp[stk.top()] = 2;
            stk.pop();
        }
    }

    int sum = 0;
    for (int i = 1; i < t; ++i) {
        if (mp[i] == 0)
            sum = 0;
        else {
            sum += mp[i];
            rst = max(rst, sum);
        }
    }

    cout << rst;
    return 0;
}