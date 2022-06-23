#include <string>
#include <vector>
#include <bitset>
#include <cstdint>
#include <cmath>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); ++i) {
        int p = 0;
        long long v = 0;
        for (p = 0; p < 64; ++p)
            if ((numbers[i] & ((long long)1 << p)) == 0) {
                v = (numbers[i] | ((long long)1 << p));
                break;
            }

        for (p = p - 1; p >= 0; p--) {
            if ((numbers[i] & ((long long)1 << p)) == ((long long)1 << p)) {
                v = (v ^ ((long long)1 << p));
                break;
            }
        }
        answer.push_back(v);
    }

    return answer;
}