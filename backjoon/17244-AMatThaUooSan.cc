#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdint>

using namespace std;

int N, M;
const int offset_y[4] = {-1, 0, 1, 0};
const int offset_x[4] = {0, 1, 0, -1};
vector<vector<char>> MAP;
vector<vector<vector<bool>>> visit;

int main() {
    cin >> N >> M;

    MAP.resize(M, vector<char>(N, '.'));
    int start_y;
    int start_x;
    int count_x = 0;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) {
            char in;
            cin >> in;

            if (in == 'S') {
                start_y = i;
                start_x = j;
                MAP[i][j] = in;
            } else if (in == 'X') {
                MAP[i][j] = (count_x++) + '0';
            } else
                MAP[i][j] = in;
        }

    visit.resize(M, vector<vector<bool>>(N, vector<bool>(1 << count_x, false)));
    queue<tuple<int, int, int, int>> q;
    int bit_count = (1 << count_x) - 1;

    q.push(make_tuple(start_y, start_x, 0, 0));
    visit[start_y][start_x][0] = true;

    while (!q.empty()) {
        auto [y, x, c, b] = q.front();
        q.pop();

        if (MAP[y][x] == 'E' && b == bit_count) {
            cout << c << endl;
            break;
        }

        for (int w = 0; w < 4; ++w) {
            int next_y = y + offset_y[w];
            int next_x = x + offset_x[w];

            if (next_y < 0 || M <= next_y || next_x < 0 || N <= next_x) continue;

            if ('0' <= MAP[next_y][next_x] && MAP[next_y][next_x] < '5') {
                int next_b = (1 << (MAP[next_y][next_x] - '0')) | b;

                if (visit[next_y][next_x][next_b]) continue;

                visit[next_y][next_x][next_b] = true;
                q.push(make_tuple(next_y, next_x, c + 1, next_b));

            } else if (MAP[next_y][next_x] != '#' && !visit[next_y][next_x][b]) {
                visit[next_y][next_x][b] = true;
                q.push(make_tuple(next_y, next_x, c + 1, b));
            }
        }
    }

    return 0;
}
