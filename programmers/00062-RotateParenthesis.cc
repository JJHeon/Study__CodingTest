#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;

    for (int count = 0; count < s.size(); ++count) {
        deque<char> t(s.begin(), s.end());
        for (int c = 0; c < count; c++) {
            t.push_back(t.front());
            t.pop_front();
        }

        stack<char> tk;
        tk.push(t[0]);
        int i = 1;
        for (i = 1; i < t.size(); ++i) {
            char pth = t[i];

            if (pth == '{' || pth == '[' || pth == '(') {
                tk.push(t[i]);
            } else if (!tk.empty()) {
                if (tk.top() == '{' && pth == '}' || tk.top() == '(' && pth == ')' || tk.top() == '[' && pth == ']')
                    tk.pop();
            } else {
                break;
            }
        }
        if (tk.empty() && i == t.size()) answer++;
        // cout << string(t.begin(), t.end()) << " " << answer << endl;
    }

    return answer;
}