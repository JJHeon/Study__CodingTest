#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;
unordered_map<string, int> m;
vector<int> COUNT_CATEGORY;
int RESULT;
void Recursive(int pos, int until, int count, int value) {
    if (until == count) {
        cout << value << endl;
        RESULT += value;
        return;
    }
    for (auto i = pos; i != COUNT_CATEGORY.size(); ++i) {
        const auto& num = COUNT_CATEGORY[i];
        cout << "until : " << until << " count : " << count << " value : " << value << " num : " << num << endl;
        Recursive(i + 1, until, count + 1, value);
        Recursive(i + 1, until, count + 1, value * num);
        cout << " ------ " << endl;
    }
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

    int sum = 1;
    for (auto i = 1; i <= m.size(); ++i) {
        Recursive(0, i, 0, 1);
        RESULT--;
    }
    answer = RESULT;
    cout << answer << endl;
    return answer;
}
