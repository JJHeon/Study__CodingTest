#include <iostream>
#include <queue>

using namespace std;

int r,
    c;
char mp[1504][1504];
int visit[1504][1504];
int swan_visit[1504][1504];
queue<pair<int, int>> q, tq;
queue<pair<int, int>> iq, tiq;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int t = 0;

int main() {
    cin >> r >> c;
    int si, sj;
    bool first = true;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mp[i][j];
            if (first && mp[i][j] == 'L') {
                q.push({i, j});
                si = i;
                sj = j;
                first = false;
            }
            if (mp[i][j] == '.' || mp[i][j] == 'L') {
                iq.push({i, j});
                visit[i][j] = 1;
            }
        }
    }
    swan_visit[si][sj] = 1;
    while (true) {
        while (q.size()) {
            auto [y, x] = q.front();
            q.pop();
            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];
                if (ny < 0 || r <= ny || nx < 0 || c <= nx || swan_visit[ny][nx]) continue;

                if (mp[ny][nx] == 'L') {
                    cout << t << "\n";
                    return 0;
                }
                swan_visit[ny][nx] = 1;
                if (mp[ny][nx] == 'X') {
                    tq.push({ny, nx});
                } else
                    q.push({ny, nx});
            }
        }

        while (iq.size()) {
            auto [y, x] = iq.front();
            iq.pop();
            for (int w = 0; w < 4; ++w) {
                int ny = y + dy[w];
                int nx = x + dx[w];
                if (ny < 0 || r <= ny || nx < 0 || c <= nx || visit[ny][nx]) continue;

                visit[ny][nx] = 1;
                if (mp[ny][nx] == 'X') {
                    tiq.push({ny, nx});
                    mp[ny][nx] = '.';
                }

                else
                    iq.push({ny, nx});
            }
        }

        q = tq;
        iq = tiq;
        queue<pair<int, int>> nq;
        queue<pair<int, int>> niq;
        tq.swap(nq);
        tiq.swap(niq);
        t++;
    }

    return 0;
}