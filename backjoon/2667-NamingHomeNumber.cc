#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> MAP;
int main() {
    cin >> N;

    MAP.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        string in;
        cin >> in;
        for (int j = 0; j < N; ++j) MAP[i][j] = in[j] - '0';
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    const int offset_y[4] = {-1, 0, 1, 0};
    const int offset_x[4] = {0, 1, 0, -1};

    int all = 0;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (!MAP[i][j]) continue;

            int count = 0;
            q.push(make_pair(i, j));
            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();
                if (visited[y][x]) continue;

                visited[y][x] = true;
                count++;

                for (int k = 0; k < 4; ++k) {
                    int next_y = y + offset_y[k];
                    int next_x = x + offset_x[k];
                    if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
                    if (!MAP[next_y][next_x]) continue;
                    q.push(make_pair(next_y, next_x));
                }
            }
            all++;
            result.push_back(count);
        }
    }

    cout << all << "\n";
    sort(result.begin(), result.end());
    for (auto v : result) cout << v << "\n";
    // //Debug
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) cout << MAP[i][j];
    //     cout << "\n";
    // }
}