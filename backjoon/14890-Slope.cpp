#include <iostream>

#include <cstring>

using namespace std;

int n;
int l;
int mp[102][102];
int vmp[102][102];
int visit[102][102];
int rst;

bool func1(int y, int x, int mp[102][102], int prev, int current) {
    if (current - 1 != prev) return false;
    for (int i = 1; i <= l; ++i) {
        if (x - i < 0) return false;
        if (mp[y][x - i] != prev) return false;
        if (visit[y][x - i]) return false;
    }

    for (int i = 1; i <= l; ++i) visit[y][x - i] = true;
    return true;
}

bool func2(int y, int x, int mp[102][102], int prev, int current) {
    if (prev - 1 != current) return false;

    for (int i = 0; i < l; ++i) {
        if (x + i >= n) return false;
        if (visit[y][x + i]) return false;
        if (current != mp[y][x + i]) return false;
    }

    for (int i = 0; i < l; ++i) visit[y][x + i] = true;
    return true;
}

int main() {
    cin >> n >> l;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> mp[i][j];

    for (int i = 0; i < n; ++i) {
        memset(visit, 0, sizeof(visit));
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                if (mp[i][j] > mp[i][j - 1]) {
                    if (!func1(i, j, mp, mp[i][j - 1], mp[i][j])) goto finish;
                } else if (mp[i][j] < mp[i][j - 1])
                    if (!func2(i, j, mp, mp[i][j - 1], mp[i][j])) goto finish;
            }
        }

        rst++;

    finish:

        continue;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) vmp[j][n - 1 - i] = mp[i][j];
    for (int i = 0; i < n; ++i) {
        memset(visit, 0, sizeof(visit));
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                if (vmp[i][j] > vmp[i][j - 1]) {
                    if (!func1(i, j, vmp, vmp[i][j - 1], vmp[i][j])) goto finish2;
                } else if (vmp[i][j] < vmp[i][j - 1]) {
                    if (!func2(i, j, vmp, vmp[i][j - 1], vmp[i][j])) goto finish2;
                }
            }
        }

        rst++;
    finish2:
        continue;
    }

    cout << rst;

    return 0;
}