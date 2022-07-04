#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<vector<vector<int>>> map(11, vector<vector<int>>(11, vector<int>(4, 0)));

    int y = 5;
    int x = 5;
    const int offset_y[4] = {1, 0, -1, 0};
    const int offset_x[4] = {0, 1, 0, -1};
    for (const char ch : dirs) {
        int select = -1;
        switch (ch) {
            case 'U':
                select = 0;
                break;
            case 'R':
                select = 1;
                break;
            case 'D':
                select = 2;
                break;
            default:
            case 'L':
                select = 3;
                break;
        }

        int next_y = y + offset_y[select];
        int next_x = x + offset_x[select];
        if (next_y < 0 || next_y > 10 || next_x < 0 || next_x > 10) continue;

        if (!map[y][x][select] || !map[next_y][next_x][(select + 2) % 4]) {
            answer++;
            map[y][x][select] = 1;
            map[next_y][next_x][(select + 2) % 4] = 1;
        }
        y = next_y;
        x = next_x;
    }

    return answer;
}