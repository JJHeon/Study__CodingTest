#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int main() {
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> r(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) map[i][j] = s[j] - '0';
    }

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));

    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [y, x, v] = q.front();
        q.pop();
        if (r[y][x]) continue;
        r[y][x] = v + 1;

        for (int i = 0; i < 4; i++) {
            int next_y = y + offset_y[i];
            int next_x = x + offset_x[i];
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
            if (!map[next_y][next_x]) continue;
            q.push(make_tuple(next_y, next_x, v + 1));
        }
    }

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) cout << map[i][j] << " ";
    //     cout << "\n";
    // }
    cout << r[N - 1][M - 1] << endl;
}