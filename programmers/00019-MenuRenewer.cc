#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

void ExtractCombination(const int num, vector<string>& combination, const string& a, const string& b) {
    string tmp;
    int count = 0;
    for (auto chitr1 = a.begin(); chitr1 != a.end(); ++chitr1)
        for (auto chitr2 = b.begin(); chitr2 != b.end(); ++chitr2)
            if (*chitr1 == *chitr2) {
                count++;
                tmp += *chitr1;
                if (num == count) {
                    sort(tmp.begin(), tmp.end());
                    combination.push_back(tmp);

                    tmp.pop_back();
                    count--;
                }
            }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    vector<string> combination;
    for (int num_course : course) {
        for (auto itr1 = orders.begin(); itr1 != orders.end() - 1; ++itr1)
            for (auto itr2 = itr1 + 1; itr2 != orders.end(); ++itr2) {
                ExtractCombination(num_course, combination, *itr1, *itr2);
            }
    }

    return answer;
}