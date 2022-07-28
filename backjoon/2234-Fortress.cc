#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
int M, N;
int main() {
    cin >> N >> M;

    vector<vector<int>> MAP(M, vector<int>(N, 0));
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(M, vector<int>(N, 0));
    const int offset_y[4] = {0, -1, 0, 1};
    const int offset_x[4] = {-1, 0, 1, 0};
    int room_count = 0;
    int maximum_size = 0;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j) cin >> MAP[i][j];

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j] > 0) continue;

            room_count += 1;

            int size = 0;
            q.push(make_tuple(i, j, 1));

            while (!q.empty()) {
                auto [y, x, c] = q.front();
                q.pop();
                if (visited[y][x] > 0) continue;

                size++;
                visited[y][x] = c;

                for (int way = 0; way < 4; way++) {
                    if ((MAP[y][x] & (1 << way)) == (1 << way)) continue;

                    int next_y = y + offset_y[way];
                    int next_x = x + offset_x[way];

                    if (next_y < 0 || M <= next_y || next_x < 0 || N <= next_x) continue;
                    if (visited[next_y][next_x] > 0) continue;

                    q.push(make_tuple(next_y, next_x, c + 1));
                }
            }

            maximum_size = max(size, maximum_size);
        }
    }

    queue<tuple<int, int, int>> q2;
    int maximum_2 = 0;

    for (int way = 0; way < 4; ++way) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((MAP[i][j] & (1 << way)) != (1 << way)) continue;

                vector<vector<int>> visited2(M, vector<int>(N, 0));

                MAP[i][j] -= (1 << way);

                q2.push(make_tuple(i, j, 1));
                int size = 0;

                while (!q2.empty()) {
                    auto [y, x, c] = q2.front();
                    q2.pop();
                    if (visited2[y][x] > 0) continue;

                    size += 1;
                    visited2[y][x] = c;

                    for (int w = 0; w < 4; w++) {
                        if ((MAP[y][x] & (1 << w)) == (1 << w)) continue;

                        int next_y = y + offset_y[w];
                        int next_x = x + offset_x[w];

                        if (next_y < 0 || M <= next_y || next_x < 0 || N <= next_x) continue;
                        if (visited2[next_y][next_x] > 0) continue;

                        q2.push(make_tuple(next_y, next_x, c + 1));
                    }
                }

                MAP[i][j] += (1 << way);

                maximum_2 = max(maximum_2, size);
            }
        }
    }
    cout << room_count << endl;
    cout << maximum_size << endl;
    cout << maximum_2 << endl;
    // for (int i = 0; i < M; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         printf("%2d ", visited2[i][j]);
    //     }
    //     cout << "\n";
    // }
    return 0;
}