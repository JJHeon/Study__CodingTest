#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    string num(number);
    for (int i = 0; i < k; ++i) {
        size_t pos = num.length() - 1;
        for (size_t j = 0; j < num.length(); ++j) {
            // current < next
            if (j + 1 < num.length() && num[j] < num[j + 1]) {
                pos = j;
                break;
            }
        }

        num.erase(num.begin() + pos);
    }
    answer = num;
    return answer;
}