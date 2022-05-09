#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int quotient = n / 3;
    int remainder = n % 3;

    int num124 = remainder;
    for (int i = 0; i < quotient; ++i) {
        num124 += 3;

        int pos = 10;
        int current = ((num124 % pos) / (pos / 10));
        while (current > 3) {
            num124 += pos;

            num124 -= 3 * (pos / 10);
            pos *= 10;
            current = ((num124 % pos) / (pos / 10));
        }
    }
    // cout << num124 << endl;

    answer += to_string(num124);
    for (char& c : answer)
        if (c == '3') c = '4';

    return answer;
}