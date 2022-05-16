#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Recursive(string u) {
    if (u == "") return "";

    int correct_pos = 0;
    int balance_pos = 0;
    int balance = 0;
    vector<char> stack;
    for (int i = 0; i < u.length(); ++i) {
        if (u[i] == '(')
            balance++;
        else
            balance--;

        if (u[i] == ')' && stack.size() > 0 && stack.back() == '(')
            stack.pop_back();
        else
            stack.push_back(u[i]);

        if (stack.size() == 0)
            correct_pos = i + 1;
        else if (correct_pos == 0 && balance == 0 && balance_pos == 0) {
            balance_pos = i + 1;
            break;
        }
    }

    string answer = "";
    if (correct_pos != 0) {
        answer += u.substr(0, correct_pos);
        answer += Recursive(u.substr(correct_pos, string::npos));
    } else {
        string result = "(" + Recursive(u.substr(balance_pos, string::npos)) + ")";
        string tmp = u.substr(1, balance_pos - 2);
        for (char& c : tmp) {
            if (c == '(')
                c = ')';
            else
                c = '(';
        }

        result += tmp;

        answer += result;
    }

    return answer;
}

string solution(string p) {
    string answer = "";
    answer = Recursive(p);
    return answer;
}