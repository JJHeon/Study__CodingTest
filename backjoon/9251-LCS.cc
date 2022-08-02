#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int RES;

int Solution() {
    string firstString;
    string secondString;
    cin >> firstString >> secondString;

    // Process
    vector<vector<int>> memorize(secondString.length() + 1, vector<int>(firstString.length() + 1, 0));

    for (int i = 0; i < secondString.length(); ++i) {
        for (int j = 0; j < firstString.length(); ++j) {
            int memorize_i = i + 1;
            int memorize_j = j + 1;

            if (secondString[i] == firstString[j]) {
                int fowradIndexJ = memorize_j - 1;
                int fowradIndexI = memorize_i - 1;

                memorize[memorize_i][memorize_j] = memorize[fowradIndexI][fowradIndexJ] + 1;
            } else {
                int bigger = std::max(memorize[memorize_i - 1][memorize_j], memorize[memorize_i][memorize_j - 1]);
                memorize[memorize_i][memorize_j] = bigger;
            }
        }
    }
    RES = memorize[secondString.length()][firstString.length()];
    // Result
    cout << RES;
    return 0;
}

int main() {
    Solution();

    return 0;
}
