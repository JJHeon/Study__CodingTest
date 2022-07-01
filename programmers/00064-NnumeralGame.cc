#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    stack<int> s;

    int value = -1;
    for (int count = 0; count < t; ++count) {
        for (int i = 1; i <= m; ++i) {
            if (s.empty()) {
                value++;
                int remainder = 0;
                int quotient = value;
                do {
                    remainder = quotient % n;
                    quotient /= n;
                    s.push(remainder);
                } while (quotient);
            }

            if (i == p) {
                char ch = 0;
                if (s.top() >= 10)
                    ch = 'A' + s.top() - 10;
                else
                    ch = '0' + s.top();

                answer.push_back(ch);
            }

            s.pop();
        }
    }

    return answer;
}