#include <iostream>
#include <vector>

using namespace std;

int N;
int MAP[17][17];
int RESULT = 0;
vector<vector<int>> que(1, vector<int>(2, 0));

inline void UpdateMap(int offset) {
}

void Soltution(int count) {
    if (count == N) {
        RESULT++;
        // cout << "------\n";
        // for (auto& t : que) {
        //     for (auto& t2 : t) cout << t2 << " ";
        //     cout << "\n";
        // }
        return;
    }

    for (int i = 1; i <= N; ++i) {
        int row = count + 1;
        int col = i;
        if (MAP[row][i] != 0) continue;

        MAP[row][i] += 1;

        for (int k = 1; k < N; ++k) {
            bool is_up = false;
            bool is_down = false;
            bool is_right = false;
            bool is_left = false;
            if (col + k <= N) {
                MAP[row][col + k] += 1;
                is_right = true;
            }
            if (col - k >= 1) {
                MAP[row][col - k] += 1;
                is_left = true;
            }
            if (row + k <= N) {
                MAP[row + k][col] += 1;
                is_down = true;
            }
            if (row - k >= 1) {
                MAP[row - k][col] += 1;
                is_up = true;
            }

            if (is_up && is_left) MAP[row - k][col - k] += 1;
            if (is_up && is_right) MAP[row - k][col + k] += 1;
            if (is_down && is_left) MAP[row + k][col - k] += 1;
            if (is_down && is_right) MAP[row + k][col + k] += 1;
        }

        Soltution(count + 1);

        MAP[row][i] -= 1;

        for (int k = 1; k < N; ++k) {
            bool is_up = false;
            bool is_down = false;
            bool is_right = false;
            bool is_left = false;
            if (col + k <= N) {
                MAP[row][col + k] -= 1;
                is_right = true;
            }
            if (col - k >= 1) {
                MAP[row][col - k] -= 1;
                is_left = true;
            }
            if (row + k <= N) {
                MAP[row + k][col] -= 1;
                is_down = true;
            }
            if (row - k >= 1) {
                MAP[row - k][col] -= 1;
                is_up = true;
            }

            if (is_up && is_left) MAP[row - k][col - k] -= 1;
            if (is_up && is_right) MAP[row - k][col + k] -= 1;
            if (is_down && is_left) MAP[row + k][col - k] -= 1;
            if (is_down && is_right) MAP[row + k][col + k] -= 1;
        }
    }
}

int main() {
    cin >> N;

    Soltution(0);
    cout << RESULT;
    cout << "\n";
    return 0;
}
