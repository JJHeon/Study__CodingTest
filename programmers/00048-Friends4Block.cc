#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
constexpr int box_y[4] = {0, 0, 1, 1};
constexpr int box_x[4] = {0, 1, 0, 1};

bool CheckValidity(vector<string>& board) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int count = 1;
            char ch = board[i][j];
            if (board[i][j] == '0') continue;
            for (int c = 1; c < 4; ++c) {
                int next_i = i + box_y[c];
                int next_j = j + box_x[c];
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) break;
                if (ch != board[next_i][next_j]) break;
                count++;
            }

            if (count == 4) return true;
        }
    }
    return false;
}
int EraseBlocks(int m, int n, vector<string>& board) {
    int blocks = 0;

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int count = 0;
            char ch = board[i][j];
            vector<pair<int, int>> buff;
            if(ch == '0') continue;
            for (int c = 0; c < 4; ++c) {
                int next_i = i + box_y[c];
                int next_j = j + box_x[c];
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) break;
                if (board[next_i][next_j] != ch) break;

                count++;
                buff.push_back(make_pair(next_i, next_j));
            }

            if (count == 4) {
                for (auto& p : buff) visited[p.first][p.second] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (visited[i][j]) {
                board[i][j] = '0';
                blocks++;
            }

    return blocks;
}
void FallAll(int m, int n, vector<string>& board) {
    for (int j = 0; j < n; ++j) {
        for (int i = m - 1; i >= 0; --i) {
            if (board[i][j] != '0') {
                int fall_pos = -1;
                for (int k = i + 1; k < m; ++k) {
                    if (board[k][j] != '0') {
                        fall_pos = k - 1;
                        break;
                    }
                }

                fall_pos = fall_pos == -1 ? m - 1 : fall_pos;

                board[fall_pos][j] = board[i][j];
                if (fall_pos != i) board[i][j] = '0';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (CheckValidity(board)) {
        answer += EraseBlocks(m, n, board);
        FallAll(m, n, board);
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << answer << endl;

    return answer;
}