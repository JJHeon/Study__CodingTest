#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    unordered_set<char> skill_order;
    for (char ch : skill) skill_order.insert(ch);

    for (auto& tree : skill_trees) {
        unordered_set<char> check(skill_order);
        int idx = 0;
        bool is_ok = true;
        for (int ch = 0; ch < tree.length(); ch++) {
            if (skill[idx] == tree[ch]) {
                idx++;
                check.erase(tree[ch]);
            } else if (check.find(tree[ch]) != check.end()) {
                is_ok = false;
                goto OUT_DOUBLE_FOR;
            } else if (idx == skill.length()) {
                is_ok = true;
                goto OUT_DOUBLE_FOR;
            }
        }

    OUT_DOUBLE_FOR:
        if (is_ok) {
            answer++;
            // cout << tree << endl;
        }
    }
    return answer;
}