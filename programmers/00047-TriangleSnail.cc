#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    int until = ((1 + n) * n) / 2;
    constexpr int dir_y[3] = {1, 0, -1};
    constexpr int dir_x[3] = {0, 1, -1};
    vector<vector<int>> v(n + 1, vector<int>(n + 1));

    int d = n;
    int count = 0;
    int w = 0;
    int y = 1;
    int x = 1;
    for (int i = 1; i <= until; ++i) {
        v[y][x] = i;
        count++;
        if (count >= d) {
            w = (w + 1) % 3;
            count = 0;
            d -= 1;
        }
        y += dir_y[w];
        x += dir_x[w];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (v[i][j]) answer.push_back(v[i][j]);

        return answer;
}