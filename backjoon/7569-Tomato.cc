#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int M, N, H;

vector<vector<vector<int>>> BOX;


int main() {
    cin >> M >> N >> H;

    BOX.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));
    vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, 0)));

    queue<tuple<int, int, int, int>> q;
    int all = 0;
    for (int k = H - 1; k >= 0; --k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j) {
                cin >> BOX[k][i][j];
                if (BOX[k][i][j] == 0) all++;
                if (BOX[k][i][j] > 0) q.push(make_tuple(k, i, j, 0));
                if (BOX[k][i][j] < 0) visited[k][i][j] = BOX[k][i][j];
            }
    if (all == 0 && q.size() > 0) {
        cout << "0\n";
        return 0;
    }

    const int offset_h[6] = {0, 0, 0, 0, -1, 1};
    const int offset_y[6] = {-1, 0, 1, 0, 0, 0};
    const int offset_x[6] = {0, 1, 0, -1, 0, 0};

    while (!q.empty()) {
        auto [h, y, x, c] = q.front();
        q.pop();
        if (visited[h][y][x]) continue;
        visited[h][y][x] = c + 1;

        for (int i = 0; i < 6; ++i) {
            int next_h = h + offset_h[i];
            int next_y = y + offset_y[i];
            int next_x = x + offset_x[i];

            if (next_h < 0 || next_h >= H || next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
            if (BOX[next_h][next_y][next_x]) continue;

            q.push(make_tuple(next_h, next_y, next_x, c + 1));
        }
    }

    int max_value = INT32_MIN;
    for (int k = H - 1; k >= 0; --k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                //cout << visited[k][i][j] << " ";
                if (!visited[k][i][j]) {
                    cout << "-1\n";
                    return 0;
                }

                max_value = max(max_value, visited[k][i][j]);
            }
            //cout << "\n";
        }
        //cout << "\n";
    }
    cout << max_value - 1 << "\n";

    // // Debug
    // cout << "\n\n";
    // for (int k = H - 1; k >= 0; --k) {
    //     for (int i = 0; i < N; ++i) {
    //         for (int j = 0; j < M; ++j) {
    //             cout << BOX[k][i][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }

    return 0;
}