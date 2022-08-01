#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int T, W, H;

const int offset_y[4] = {-1, 0, 1, 0};
const int offset_x[4] = {0, 1, 0, -1};

int main() {
    vector<string> result_all;

    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        cin >> W >> H;

        vector<vector<char>> MAP(H, vector<char>(W, '.'));
        vector<vector<int>> V(H, vector<int>(W, 0));
        queue<tuple<int, int, char, int>> q;
        int s_y, s_x;

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                char in;
                cin >> in;
                MAP[i][j] = in;

                if (in == '@') {
                    V[i][j] = 1;
                    s_y = i;
                    s_x = j;

                } else if (in == '*') {
                    V[i][j] = -1;
                    q.push(make_tuple(i, j, '*', 0));
                }
            }
        }

        q.push(make_tuple(s_y, s_x, '@', 1));

        while (!q.empty()) {
            auto [y, x, type, c] = q.front();
            q.pop();

            if ((type == '@' && MAP[y][x] != '#') && (y == 0 || y == H - 1 || x == 0 || x == W - 1)) {
                result_all.push_back(to_string(c));
                goto FINISH_TC;
            }

            for (int w = 0; w < 4; ++w) {
                int ny = y + offset_y[w];
                int nx = x + offset_x[w];

                if (ny < 0 || H <= ny || nx < 0 || W <= nx) continue;
                if (MAP[ny][nx] == '#') continue;

                if (type == '*') {
                    if (V[ny][nx] == -1) continue;

                    V[ny][nx] = -1;
                    q.push(make_tuple(ny, nx, '*', 0));
                } else if (type == '@') {
                    if (V[ny][nx] > 0) continue;
                    if (V[ny][nx] == -1) continue;

                    V[ny][nx] = c + 1;
                    q.push(make_tuple(ny, nx, '@', c + 1));
                }
            }
        }
        // for (int i = 0; i < H; ++i){
        //     for (int j = 0; j < W; ++j){
        //         printf("%2d ", V[i][j]);
        //     }
        //     cout << "\n";
        // }

        result_all.push_back("IMPOSSIBLE");
    FINISH_TC:
        continue;
    }

    for (auto s : result_all) cout << s << endl;
    return 0;
}