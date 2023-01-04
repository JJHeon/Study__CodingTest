#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int OFFSET_Y[4] = {-1, 0, 1, 0};
int OFFSET_X[4] = {0, 1, 0, -1};
char MAP[1001][1001];
bool MOVE[1001][1001];
bool FMOVE[1001][1001];
int R, C;

int Solution() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> fq;

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            char in;
            cin >> in;
            if (in == 'J') {
                q.push(make_pair(i, j));
                in = '.';
            }

            else if (in == 'F')
                fq.push(make_pair(i, j));
            MAP[i][j] = in;
        }
    {
        queue<pair<int, int>> fnq;
        while (!fq.empty()) {
            auto [y, x] = fq.front();
            fq.pop();
            if (FMOVE[y][x]) continue;

            FMOVE[y][x] = true;

            for (int way = 0; way < 4; ++way) {
                int next_y = y + OFFSET_Y[way];
                int next_x = x + OFFSET_X[way];

                if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) continue;
                if (MAP[next_y][next_x] == '#') continue;
                fnq.push(make_pair(next_y, next_x));
            }
        }
        fq = fnq;
    }

    int timer = 0;
    while (true) {
        timer++;

        queue<pair<int, int>> fnq;
        while (!fq.empty()) {
            auto [y, x] = fq.front();
            fq.pop();
            if (FMOVE[y][x]) continue;

            FMOVE[y][x] = true;

            for (int way = 0; way < 4; ++way) {
                int next_y = y + OFFSET_Y[way];
                int next_x = x + OFFSET_X[way];

                if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) continue;
                if (MAP[next_y][next_x] == '#') continue;
                fnq.push(make_pair(next_y, next_x));
            }
        }
        fq = fnq;

        queue<pair<int, int>> nq;
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            if (MOVE[y][x]) continue;

            MOVE[y][x] = true;

            for (int way = 0; way < 4; ++way) {
                int next_y = y + OFFSET_Y[way];
                int next_x = x + OFFSET_X[way];

                if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) return timer;
                if (FMOVE[next_y][next_x] || MAP[next_y][next_x] != '.') continue;

                nq.push(make_pair(next_y, next_x));
            }
        }
        if (nq.empty()) return -1;
        q = nq;

        // //debug
        // cout << timer << endl;
        // cout << "Fire" << endl;
        // for (int i = 0; i < R; ++i) {
        //     for (int j = 0; j <  C; ++j){
        //         if (FMOVE[i][j]) cout << "1";
        //         else
        //             cout << "0";
        //     }
        //     cout << "\n";
        // }
        // cout << "PEOPLE" << endl;
        // for (int i = 0; i < R; ++i) {
        //     for (int j = 0; j <  C; ++j){
        //         if (MOVE[i][j]) cout << "1";
        //         else
        //             cout << "0";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n\n\n";
    }
}

int main() {
    int result = Solution();
    if (result == -1)
        cout << "IMPOSSIBLE";
    else
        cout << result;
    return 0;
}