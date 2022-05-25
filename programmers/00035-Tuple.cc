#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    bool open_set = false;
    int start_num_pos = 0;
    int end_num_pos = 0;
    int num_sets = 0;
    vector<vector<int>> sets;
    for (int i = 1; i < s.size() - 1; ++i) {
        if (s[i] == '{') {
            open_set = true;
            start_num_pos = i + 1;
            sets.push_back(vector<int>());
            continue;
        } else if (s[i] == '}') {
            open_set = false;
            end_num_pos = i;

            int num = stoi(s.substr(start_num_pos, end_num_pos));
            sets[num_sets].push_back(num);
            num_sets++;
            continue;
        } else if (open_set && s[i] == ',') {
            end_num_pos = i;
            int num = stoi(s.substr(start_num_pos, end_num_pos));
            sets[num_sets].push_back(num);

            start_num_pos = i + 1;
            continue;
        }
    }

    sort(sets.begin(), sets.end(), [](vector<int>& a, vector<int>& b) -> bool {
        return a.size() < b.size();
    });

    unordered_set<int> hash;

    for (int i = 0; i < sets.size(); ++i) {
        for (int j = 0; j < sets[i].size(); ++j) {
            if (hash.find(sets[i][j]) == hash.end()) {
                hash.insert(sets[i][j]);
                answer.push_back(sets[i][j]);
            }
        }
    }

    return answer;
}