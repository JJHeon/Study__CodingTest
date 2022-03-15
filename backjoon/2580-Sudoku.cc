#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

int SUDOCOO[11][11];
constexpr int SUDOCOO_SIZE = 9;
vector<pair<int, int>> TARGET;
bool ROW_SELECTED[11][11];
bool COL_SELECTED[11][11];
bool SQUARE_SELECTED[11][11];
bool only_once = true;
int JudgeInSquare(const int& i, const int& j) {
    if (1 <= i && i <= 3) {
        if (1 <= j && j <= 3)
            return 1;
        else if (4 <= j && j <= 6)
            return 2;
        else
            return 3;
    } else if (4 <= i && i <= 6) {
        if (1 <= j && j <= 3)
            return 4;
        else if (4 <= j && j <= 6)
            return 5;
        else
            return 6;
    } else {
        if (1 <= j && j <= 3)
            return 7;
        else if (4 <= j && j <= 6)
            return 8;
        else
            return 9;
    }
    return 0;
}

void Solution(int count) {
    if (count == TARGET.size()) {
        for (int i = 1; i <= SUDOCOO_SIZE; ++i) {
            for (int j = 1; j <= SUDOCOO_SIZE; ++j) {
                // cout << SUDOCOO[i][j] << " ";
                printf("%d ", SUDOCOO[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    pair<int, int> selected_item = TARGET[count];
    const int target_i = selected_item.first;
    const int target_j = selected_item.second;

    const int target_square = JudgeInSquare(target_i, target_j);

    for (int num = 1; num <= SUDOCOO_SIZE; ++num) {
        if (ROW_SELECTED[target_i][num]) continue;
        if (COL_SELECTED[target_j][num]) continue;
        if (SQUARE_SELECTED[target_square][num]) continue;

        SUDOCOO[target_i][target_j] = num;
        ROW_SELECTED[target_i][num] = true;
        COL_SELECTED[target_j][num] = true;
        SQUARE_SELECTED[target_square][num] = true;

        Solution(count + 1);

        SUDOCOO[target_i][target_j] = 0;
        ROW_SELECTED[target_i][num] = false;
        COL_SELECTED[target_j][num] = false;
        SQUARE_SELECTED[target_square][num] = false;
    }
}

int main() {
    // input
    for (int i = 1; i <= SUDOCOO_SIZE; ++i)
        for (int j = 1; j <= SUDOCOO_SIZE; ++j) {
            cin >> SUDOCOO[i][j];

            ROW_SELECTED[i][SUDOCOO[i][j]] = true;
            COL_SELECTED[j][SUDOCOO[i][j]] = true;
            SQUARE_SELECTED[JudgeInSquare(i, j)][SUDOCOO[i][j]] = true;

            if (SUDOCOO[i][j] == 0)
                TARGET.push_back(make_pair(i, j));
        }

    Solution(0);
    return 0;
}