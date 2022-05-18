#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int kDIR[4] = {0, 1, 2, 3};  // UP, RIGHT, DOWN, LEFT
constexpr int kDIR_OFFSET_Y[4] = {-1, 0, 1, 0};
constexpr int kDIR_OFFSET_X[4] = {0, 1, 0, -1};
bool is_visited[500][500][4];  // 4 MByte
vector<int> result;

void Recursive(int y, int x, int dir, int count, vector<string>& grid) {
    if (is_visited[y][x][dir]) {
        if (count != 0) result.push_back(count);
        return;
    }

    is_visited[y][x][dir] = true;

    int y_size = grid.size();
    int x_size = grid[0].length();
    
        //'S' 는 dir 그대로
    if (grid[y][x] == 'R') {
        dir = (dir + 1) % 4;
    } else if (grid[y][x] == 'L') {
        dir = (dir + 3) % 4;
    }

    int next_y = y + kDIR_OFFSET_Y[dir];
    int next_x = x + kDIR_OFFSET_X[dir];
    next_y = next_y < 0 ? y_size - 1 : (next_y >= y_size ? 0 : next_y);
    next_x = next_x < 0 ? x_size - 1 : (next_x >= x_size ? 0 : next_x);


    Recursive(next_y, next_x, dir, count + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    int size_y = grid.size();
    int size_x = grid[0].length();

    for (int y = 0; y < size_y; ++y) {
        for (int x = 0; x < size_x; ++x) {
            for (int d = 0; d < 4; ++d) {
                    Recursive(y, x, d, 0, grid);
            }
        }
    }

    answer = result;
    sort(answer.begin(), answer.end());
    return answer;
}