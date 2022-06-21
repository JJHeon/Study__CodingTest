#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int count_zero = 0;
    int count_transformation = 0;
    while (s != "1") {
        int length = 0;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '1') length++;
        count_zero += (s.length() - length);

        // Make Binary
        stack<int> t;
        do {
            int c = length % 2;
            length = length / 2;
            t.push(c);
        } while (length != 0);

        string binary = "";
        while (!t.empty()) {
            binary += to_string(t.top());
            t.pop();
        }
        //--> MakeBinary
        s = binary;

        count_transformation++;
    }
    answer.push_back(count_transformation);
    answer.push_back(count_zero);

    return answer;
}