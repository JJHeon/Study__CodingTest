#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool IsFinsihed(vector<vector<bool>>& foot_print) {
    for (auto row : foot_print) {
        if (find(row.begin(), row.end(), false) != row.end()) return false;
    }
    return true;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> foot_print(m, vector<bool>(n, false));
    stack<pair<int, int>> bfs;
    stack<pair<int, int>> bucket;

    //최초 유효 픽셀 탐색
    bool only_once = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (picture[i][j] == 0)
                foot_print[i][j] = true;
        }
    }

    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            if (foot_print[y][x]) continue;
            if (picture[y][x]) {
                number_of_area++;
                int nextIoffset[4] = {-1, 0, 1, 0};
                int nextJoffset[4] = {0, 1, 0, -1};
                int count = 0;

                bfs.push(make_pair(y, x));
                while (bfs.size()) {
                    auto [i, j] = bfs.top();
                    bfs.pop();
                    if (foot_print[i][j]) continue;  // bucket에 같은색 others가 포함되어 있는 경우

                    foot_print[i][j] = true;
                    count++;

                    for (int w = 0; w < 4; ++w) {
                        const int nextI = i + nextIoffset[w];
                        const int nextJ = j + nextJoffset[w];
                        const int currentColor = picture[i][j];

                        if (nextI < 0 || nextI >= m || nextJ < 0 || nextJ >= n)
                            continue;
                        else if (foot_print[nextI][nextJ])
                            continue;
                        else if (picture[nextI][nextJ] != currentColor)
                            continue;
                        else
                            bfs.push(make_pair(nextI, nextJ));
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, count);
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}