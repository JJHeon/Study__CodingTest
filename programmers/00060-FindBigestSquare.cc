#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    const int row_size = board.size();
    const int col_size = board[0].size();
    const int i_offset[4] = {0, 0, 1, 1};
    const int j_offset[4] = {0, 1, 0, 1};
    for (int i = row_size - 1; i >= 0; --i) {
        for (int j = col_size - 1; j >= 0; --j) {
            if (!board[i][j]) continue;

            // Check
            int min = INT32_MAX;
            for (int k = 1; k < 4; ++k) {
                int next_i = i + i_offset[k];
                int next_j = j + j_offset[k];

                if (next_i < 0 || next_i >= row_size || next_j < 0 || next_j >= col_size) goto OUT_DOUBLE_FOR;
                if (!board[next_i][next_j]) goto OUT_DOUBLE_FOR;
                min = std::min(board[next_i][next_j], min);
            }

            // then
            board[i][j] = min + 1;

        OUT_DOUBLE_FOR:
            answer = std::max(board[i][j], answer);
            continue;
        }
    }
    
    // Debug
    // for (int i = 0; i < row_size; ++i) {
    //     for (int j = 0; j < col_size; ++j) cout << board[i][j] << " ";
    //     cout << "\n";
    // }

    return answer * answer;
}