#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;
unordered_map<string, int> m;
vector<int> COUNT_CATEGORY;
int RESULT;
void Recursive(int until, int count, int value) {
    if (until == count) {
        RESULT += value;
        return;
    }
    const auto& num = COUNT_CATEGORY[count];
    Recursive(until, count + 1, value);
    Recursive(until, count + 1, value * num);
}
int solution(vector<vector<string>> clothes) {
    int answer = 0;

    for (const auto& elem : clothes) {
        const auto& name = elem[0];
        const auto& category = elem[1];
        m[category]++;
    }
    for (auto itr = m.begin(); itr != m.end(); ++itr)
        COUNT_CATEGORY.push_back((*itr).second);

    Recursive(COUNT_CATEGORY.size(), 0, 1);
    RESULT--;

    answer = RESULT;
    cout << answer << endl;
    return answer;
}
