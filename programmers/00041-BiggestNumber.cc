#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool Compare(const string& a, const string& b) {
    string t1 = a + b;
    string t2 = b + a;
    return stoi(t1) > stoi(t2);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str(numbers.size());
    for (int i = 0; i < numbers.size(); ++i) str[i] = to_string(numbers[i]);

    sort(str.begin(), str.end(), Compare);

    for (auto s : str) answer += s;

    if (answer[0] == '0') answer = "0";
    return answer;
}