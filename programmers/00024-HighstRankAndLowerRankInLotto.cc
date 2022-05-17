#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int num_zero = 0;
    int num_equals = 0;
    for (int i = 0; i < lottos.size(); ++i) {
        if (lottos[i] == 0) {
            num_zero++;
            continue;
        }
        for (int j = 0; j < win_nums.size(); ++j) {
            if (win_nums[j] == lottos[i]) {
                num_equals++;
                break;
            }
        }
    }

    int highest = 0;
    int lowest = 0;
    if (num_zero == 0) {
        int value = (num_equals - 7) * -1;
        if (value == 7) value = 6;

        highest = lowest = value;
    } else if (num_equals == 0) {
        highest = 1;
        lowest = 6;
    } else {
        highest = ((num_equals + num_zero) - 7) * -1;

        lowest = (num_equals - 7) * -1;
        if (lowest == 7) lowest = 6;
    }
    answer.push_back(highest);
    answer.push_back(lowest);

    return answer;
}