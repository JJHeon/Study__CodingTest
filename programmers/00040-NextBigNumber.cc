#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    if ((n << 1) < -1) return answer = 0;
    int num = n;
    int i = 0;
    for (i = 0; i < 31; ++i) {
        if (((num & (1 << i)) == (1 << i)) && ((num & (1 << (i + 1))) != (1 << i + 1))) {
            num = (num | (1 << i + 1));
            num = (num ^ (1 << i));

            break;
        }
    }
    for (int j = 0; j < i; ++j) {
        int pos = (1 << j);
        if ((num & pos) == pos) {
            int k = j - 1;
            for (k = j - 1; k >= 0; --k) {
                if ((num & (1 << k)) == (1 << k)) {
                    break;
                }
            }

            num = (num ^ pos);
            num = (num | (1 << (k + 1)));
        }
    }

    answer = num;
    return answer;
}