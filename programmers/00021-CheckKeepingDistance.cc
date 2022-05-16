#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto row = places.begin(); row != places.end(); ++row) {
        vector<pair<int, int>> people;

        // Search P
        for (auto col = (*row).begin(); col != (*row).end(); ++col) {
            int y = col - (*row).begin();
            for (auto c = (*col).begin(); c != (*col).end(); ++c) {
                int x = c - (*col).begin();

                if (*c == 'P') people.push_back(make_pair(y, x));
            }
        }

        // Check P
        bool is_ok = true;
        for (auto t1 = people.begin(); t1 != people.end(); ++t1) {
            for (auto t2 = t1 + 1; t2 != people.end(); ++t2) {
                auto [t1_y, t1_x] = (*t1);
                auto [t2_y, t2_x] = (*t2);
                if (std::abs(t1_y - t2_y) + std::abs(t1_x - t2_x) <= 2) {
                    int offset_y = (t1_y == t2_y ? 0 : (t1_y < t2_y ? 1 : -1));
                    int offset_x = (t1_x == t2_x ? 0 : (t1_x < t2_x ? 1 : -1));
                    int i;
                    int j;

                    // First Y
                    if (offset_y != 0) {
                        i = t1_y + offset_y;
                        j = t1_x;
                        if ((*row)[i][j] != 'X') {
                            is_ok = false;
                            goto OUT_DOUBLE_FOR;
                        }
                    }
                    // First X
                    if (offset_x != 0) {
                        i = t1_y;
                        j = t1_x + offset_x;
                        if ((*row)[i][j] != 'X') {
                            is_ok = false;
                            goto OUT_DOUBLE_FOR;
                        }
                    }
                }
            }
        }
    OUT_DOUBLE_FOR:
        if (is_ok)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}