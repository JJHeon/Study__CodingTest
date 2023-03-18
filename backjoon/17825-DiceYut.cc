#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int value[101];
vector<int> adj[101];
int mv[4];
int dice[10];
int rst;

int move(int cp, int cnt) {
    if (cp == 100) return 100;
    if (adj[cp].size() >= 2) {
        cp = adj[cp][1];
        cnt--;
    }

    if (cnt) {
        queue<int> q;
        q.push(cp);
        int np;
        while (q.size()) {
            int p = q.front();
            q.pop();
            np = adj[p][0];
            if (np == 100) break;
            cnt--;
            if (cnt == 0) break;
            q.push(np);
        }
        return np;
    } else
        return cp;
}
bool check(int p, int idx) {
    if (p == 100) return false;
    for (int i = 0; i < 4; ++i) {
        if (i == idx) continue;
        if (p == mv[i]) return true;
    }
    return false;
}
int sol(int cnt) {
    if (cnt == 10) return 0;

    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int tmp = mv[i];
        int np = move(mv[i], dice[cnt]);
        if (check(np, i)) continue;

        mv[i] = np;
        ret = max(ret, sol(cnt + 1) + value[np]);
        mv[i] = tmp;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 20; ++i) adj[i].push_back(i + 1);
    adj[5].push_back(21);
    adj[21].push_back(22);
    adj[22].push_back(23);
    adj[23].push_back(29);

    adj[10].push_back(24);
    adj[24].push_back(25);
    adj[25].push_back(29);

    adj[15].push_back(26);
    adj[26].push_back(27);
    adj[27].push_back(28);
    adj[28].push_back(29);

    adj[29].push_back(30);
    adj[30].push_back(31);
    adj[31].push_back(20);
    adj[20].push_back(100);

    value[0] = 0;
    value[1] = 2;
    value[2] = 4;
    value[3] = 6;
    value[4] = 8;
    value[5] = 10;
    value[6] = 12;
    value[7] = 14;
    value[8] = 16;
    value[9] = 18;
    value[10] = 20;
    value[11] = 22;
    value[12] = 24;
    value[13] = 26;
    value[14] = 28;
    value[15] = 30;
    value[16] = 32;
    value[17] = 34;
    value[18] = 36;
    value[19] = 38;
    value[20] = 40;
    value[21] = 13;
    value[22] = 16;
    value[23] = 19;
    value[24] = 22;
    value[25] = 24;
    value[26] = 28;
    value[27] = 27;
    value[28] = 26;
    value[29] = 25;
    value[30] = 30;
    value[31] = 35;
    value[100] = 0;

    for (int i = 0; i < 10; ++i) cin >> dice[i];

    rst = sol(0);

    cout << rst;
    return 0;
}