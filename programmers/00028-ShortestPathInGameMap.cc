#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int solution(vector<vector<int> > maps) {
    int answer = -1;
    const int n = maps.size();
    const int m = maps[0].size();
    bool visited[101][101] = {
        false,
    };

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};
    queue<tuple<int, int, int>> s;

    s.push(make_tuple(0, 0, 1));
    visited[0][0] = true;
    while (!s.empty()) {
        auto [i, j, c] = s.front();
        s.pop();

        if(i == n-1 && j == m-1) {
            answer = c;
            break;
        }

        for (int way = 0; way < 4; ++way){
            int next_i = i + offset_y[way];
            int next_j = j + offset_x[way];
            if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
            if(visited[next_i][next_j]) continue;
            if(maps[next_i][next_j] == 0) continue;

            visited[next_i][next_j] = true;
            s.push(make_tuple(next_i, next_j, c + 1));
        }
    }

    return answer;
}