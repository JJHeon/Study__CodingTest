#include <iostream>
#include <vector>

using namespace std;

bool Recursive(int y, int x, int way, int count, char comp, vector<vector<char>>& map) {
    if (count >= 3) return true;
    if (y < 0 || 3 <= y || x < 0 || 3 <= x) return false;
    if (map[y][x] != comp) return false;

    switch (way) {
        case 0:
            return Recursive(y, x + 1, way, count + 1, comp, map);
            break;
        case 1:
            return Recursive(y + 1, x + 1, way, count + 1, comp, map);
            break;
        case 2:
            return Recursive(y + 1, x, way, count + 1, comp, map);
            break;
        case 3:
            return Recursive(y + 1, x - 1, way, count + 1, comp, map);
            break;
        default:
            break;
    }
}
bool Check(vector<vector<char>>& map, char comp) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] == comp) {
                for (int way = 0; way < 4; ++way) {
                    if (Recursive(i, j, way, 0, comp, map)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, '.'));
    string in = "";
    vector<string> answer;

    while (true) {
        string result = "";
        cin >> in;
        if (in == "end") break;

        int count_x = 0;
        int count_o = 0;
        int count_dot = 0;
        for (int i = 0; i < 9; i++) {
            board[i / 3][i % 3] = in[i];
            switch (in[i]) {
                case 'X':
                    count_x++;
                    break;
                case 'O':
                    count_o++;
                    break;
                case '.':
                    count_dot++;
                    break;
                default:
                    break;
            }
        }

        if (count_o <= count_x && count_x <= count_o + 1) {
            if (count_o < count_x) {
                if (Check(board, 'X') && !Check(board, 'O')) {
                    answer.push_back("valid");
                } else if (Check(board, 'O')) {
                    answer.push_back("invalid");

                } else if (count_dot > 0) {
                    answer.push_back("invalid");
                    continue;
                } else
                    answer.push_back("valid");
                // x exits, o no
                // else : count_dot > 0 then invalid
            } else if (count_o == count_x) {
                if (Check(board, 'O') && !Check(board, 'X')) {
                    answer.push_back("valid");
                } else if (Check(board, 'X'))
                    answer.push_back("invalid");

                else if (count_dot > 0) {
                    answer.push_back("invalid");
                    continue;
                } else
                    answer.push_back("valid");
                // x exits, o no
                // o exits, x no
                // else : count_dot > 0 then invalid
            }

        } else {
            answer.push_back("invalid");
            continue;
        }
    }
    for (auto s : answer) cout << s << endl;

    return 0;
}