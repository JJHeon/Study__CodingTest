#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> set;

    int last_num = 0;
    int when = 0;
    char previous = *(words[0].begin());
    for (int i = 0; i < words.size(); ++i) {
        if (set.find(words[i]) != set.end() || previous != words[i][0]) {
            last_num = (i % n) + 1;
            when = i / n + 1;
            break;
        }

        set.insert(words[i]);
        previous = *(words[i].end() - 1);
    }
    answer.push_back(last_num);
    answer.push_back(when);
    return answer;
}