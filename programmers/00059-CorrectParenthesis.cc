#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    vector<char> stack;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            stack.push_back(s[i]);
        } else {
            if (stack.size() > 0 && stack[stack.size() - 1] == '(') {
                stack.pop_back();
            } else {
                return false;
            }
        }
    }
    if (stack.size())
        answer = false;
    else
        answer = true;
    return answer;
}