#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cstdint>
#include <algorithm>
#include <cstdint>

using namespace std;

int N, M;
vector<bool> VISIT;
vector<int> PICK;
vector<pair<int, int>> VIRUS;
int NUM_EMPTY = 0;
vector<vector<int>> MAP;
int RESULT = INT32_MAX;

const int OFFSET_Y[4] = {-1, 0, 1, 0};
const int OFFSET_X[4] = {0, 1, 0, -1};

void DFS(int count, int next, int total) {
    if (count >= M) {
        vector<vector<int>> QMAP(MAP);
        queue<tuple<int, int, int>> QQ;
        int num_virus = 0;
        int time = 0;
        int maximum = 0;

        for (auto p : PICK) {
            auto [y, x] = VIRUS[p];
            QQ.push(make_tuple(y, x, 1));
        }

        while (!QQ.empty()) {
            auto [y, x, v] = QQ.front();
            QQ.pop();
            if (QMAP[y][x] > 0) continue;

            if (QMAP[y][x] != -1) num_virus++;
            QMAP[y][x] = v;
            maximum = max(maximum, v);

            if (NUM_EMPTY == num_virus) {
                break;
            }

            for (int way = 0; way < 4; way++) {
                int next_y = y + OFFSET_Y[way];
                int next_x = x + OFFSET_X[way];
                if (next_y < 0 || N <= next_y || next_x < 0 || N <= next_x) continue;
                if (QMAP[next_y][next_x] == -2) continue;  // wall
                if (QMAP[next_y][next_x] > 0) continue;    // already virus

                QQ.push(make_tuple(next_y, next_x, v + 1));
            }
        }
        if (NUM_EMPTY == num_virus) RESULT = min(RESULT, maximum - 1);

        // // DEBUG
        // cout << "\n\nNUMEMPTY : " << NUM_EMPTY << " , num_virus : " << num_virus << " , Sele1cted : ";
        // for (auto p : PICK) cout << p << " ";
        // cout << "\n";
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) printf("%2d ", QMAP[i][j]);
        //     cout << "\n";
        // }

        return;
    }

    for (int i = next; i < total; ++i) {
        if (VISIT[i]) continue;
        VISIT[i] = true;
        PICK.push_back(i);
        DFS(count + 1, i + 1, total);
        PICK.pop_back();
        VISIT[i] = false;
    }
}
int main() {
    cin >> N >> M;

    MAP.assign(N, vector<int>(N, 0));
    int total = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int in;
            cin >> in;
            if (in == 2) {
                VIRUS.push_back(make_pair(i, j));
                MAP[i][j] = -1;
                total++;
            } else if (in == 1)
                MAP[i][j] = -2;
            else
                NUM_EMPTY++;
        }

    VISIT.assign(total, false);
    DFS(0, 0, total);

    if (RESULT == INT32_MAX)
        cout << "-1\n";
    else
        cout << RESULT << "\n";
    return 0;
}