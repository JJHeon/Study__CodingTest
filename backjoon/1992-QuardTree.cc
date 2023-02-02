#include <cstdio>
#include <string>

using namespace std;

int n;
int map[72][72];
string rst = "";

bool check(int sy, int sx, int n) {
    int base = map[sy][sx];
    for (int i = sy; i < sy + n; ++i) {
        for (int j = sx; j < sx + n; ++j) {
            if (map[i][j] != base) {
                return false;
            }
        }
    }
    return true;
}


void dfs(int sy, int sx, int n) {
    if (n == 1){
        rst += ('0' + map[sy][sx]);
        return;
    }

    if(!check(sy,sx,n)){
        int nxt = n / 2;
        rst += '(';

        dfs(sy, sx, nxt);
        dfs(sy, sx + nxt, nxt);
        dfs(sy + nxt, sx, nxt);
        dfs(sy + nxt, sx + nxt, nxt);

        rst += ')';
    }
    else
        rst += ('0' + map[sy][sx]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) scanf("%1d", &map[i][j]);
    }
    dfs(0, 0, n);
    printf("%s\n", rst.c_str());

    return 0;
}