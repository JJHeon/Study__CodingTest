#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M, T;

int main() {
    cin >> N >> M >> T;

    vector<vector<int>> MAP(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> MAP[i][j];

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};
    vector<vector<int>> visited(N, vector<int>(M, 0));
    vector<vector<int>> visited2(N, vector<int>(M, 0));
    queue<tuple<int, int, int>> q;
    int gram_y, gram_x, gram_time;
    int reach_no_gram_time = T + 1;
    int reach_gram_time = T + 1;
    bool is_gram = false;

    q.push(make_tuple(0, 0, 1));

    // without gram
    while (!q.empty()) {
        auto [y, x, c] = q.front();
        q.pop();

        if (visited[y][x] > 0) continue;
        if (MAP[y][x] == 2) {
            gram_y = y;
            gram_x = x;
            gram_time = c;
            is_gram = true;
        }

        visited[y][x] = c;

        if (y == N - 1 && x == M - 1) {
            reach_no_gram_time = c - 1;
            break;
        }

        for (int way = 0; way < 4; ++way) {
            int next_y = y + offset_y[way];
            int next_x = x + offset_x[way];

            if (next_y < 0 || N <= next_y || next_x < 0 || M <= next_x) continue;
            if (MAP[next_y][next_x] == 1) continue;

            q.push(make_tuple(next_y, next_x, c + 1));
        }
    }

    while (!q.empty()) q.pop();

    if (is_gram) {
        // after gram
        q.push(make_tuple(gram_y, gram_x, gram_time));
        while (!q.empty()) {
            auto [y, x, c] = q.front();
            q.pop();

            if (visited2[y][x] > 0) continue;

            visited2[y][x] = c;

            if (y == N - 1 && x == M - 1) {
                reach_gram_time = c - 1;
                break;
            }

            for (int way = 0; way < 4; ++way) {
                int next_y = y + offset_y[way];
                int next_x = x + offset_x[way];

                if (next_y < 0 || N <= next_y || next_x < 0 || M <= next_x) continue;

                q.push(make_tuple(next_y, next_x, c + 1));
            }
        }
    }

    int minimum = min(reach_gram_time, reach_no_gram_time);
    if (minimum > T)
        cout << "Fail\n";
    else
        cout << minimum << "\n";

    // cout << "\n\n";
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         printf("%2d  ", visited[i][j]);
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         printf("%2d  ", visited2[i][j]);
    //     }
    //     cout << "\n";
    // }

    return 0;
}