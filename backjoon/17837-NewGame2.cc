#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int N, K;
constexpr int kWhite = 0;
constexpr int kRed = 1;
constexpr int kBlue = 2;
const int OFFSET_Y[5] = {0, 0, 0, -1, 1};
const int OFFSET_X[5] = {0, 1, -1, 0, 0};
int MAP[13][13];
int MOVE[13][13][11];

vector<tuple<int, int, int>> MALS(1);

void ChangeWay(int& way) {
    switch (way) {
        case 1:
            way = 2;
            break;
        case 2:
            way = 1;
            break;
        case 3:
            way = 4;
            break;
        case 4:
            way = 3;
        default:
            break;
    }
}

int Solution() {
    int result = -1;
    for (int turn = 1; turn <= 1000; ++turn) {
        for (int m = 1; m <= K; ++m) {
            auto& [ry, rx, way] = MALS[m];
            int y = ry;
            int x = rx;
            int next_y = y + OFFSET_Y[way];
            int next_x = x + OFFSET_X[way];

            int start_h = 0;
            int end_h = 0;
            for (int h = 1; h <= K; ++h) {
                if (MOVE[y][x][h] == m)
                    start_h = h;
                else if (MOVE[y][x][h] == 0) {
                    end_h = h - 1;
                    break;
                }
            }
            // cout << "t : " << turn << ", m : " << m << ", y : " << y << ", x : " << x << ", next_y : " << next_y << ", next_x : " << next_x << " - ";

            if ((next_y > N || next_y < 1 || next_x > N || next_x < 1) || MAP[next_y][next_x] == kBlue) {
                ChangeWay(way);
                int new_next_y = y + OFFSET_Y[way];
                int new_next_x = x + OFFSET_X[way];
                // cout << "Blue , new_next_y : " << new_next_y << ", new_next_x : " << new_next_x << ", ~ ";
                if ((new_next_y > N || new_next_y < 1 || new_next_x > N || new_next_x < 1) || MAP[new_next_y][new_next_x] == kBlue) {
                    // cout << " out\n";
                    continue;
                }

                next_y = new_next_y;
                next_x = new_next_x;
            }

            if (MAP[next_y][next_x] == kRed) {
                for (int h = 1; h <= K; ++h)
                    if (MOVE[next_y][next_x][h] == 0) {
                        // cout << ", h : " << h << " ";
                        int sh = h;
                        for (int pre_h = end_h; start_h <= pre_h; --pre_h) {
                            int move_item = MOVE[y][x][pre_h];
                            auto& [fy, fx, fway] = MALS[move_item];
                            fy = next_y;
                            fx = next_x;
                            MOVE[y][x][pre_h] = 0;
                            MOVE[next_y][next_x][sh++] = move_item;
                        }
                        if (sh >= 5)
                            return turn;

                        // cout << "In Red\n";
                        break;
                    }
            }
            // White
            else {
                for (int h = 1; h <= K; ++h)
                    if (MOVE[next_y][next_x][h] == 0) {
                        // cout << ", h : " << h << " ";
                        int sh = h;
                        for (int pre_h = start_h; pre_h <= end_h; ++pre_h) {
                            int move_item = MOVE[y][x][pre_h];
                            auto& [fy, fx, fway] = MALS[move_item];
                            fy = next_y;
                            fx = next_x;
                            MOVE[y][x][pre_h] = 0;
                            MOVE[next_y][next_x][sh++] = move_item;
                        }
                        if (sh >= 5) return turn;

                        // cout << "In White\n";
                        break;
                    }
            }
        }
    }
    return result;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j) cin >> MAP[i][j];

    for (int i = 1; i <= K; i++) {
        int y, x, way;
        cin >> y >> x >> way;

        MALS.push_back(make_tuple(y, x, way));
        for (int h = 1; h <= K; ++h) {
            if (h >= 4) {
                cout << "0\n";
                return 0;
            }
            if (MOVE[y][x][h] == 0) {
                MOVE[y][x][h] = i;
                break;
            }
        }
    }

    int result = Solution();
    cout << result << endl;

    return 0;
}