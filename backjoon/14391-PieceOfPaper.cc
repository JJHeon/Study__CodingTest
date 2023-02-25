#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int mp[6][6];
int rst;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%1d", &mp[i][j]);

    for (int w = 0; w < (1 << (n * m)); ++w) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                int k = m * i + j;
                if ((w & (1 << k)) == 0) {
                    cur = cur * 10 + mp[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int j = 0; j < m; ++j) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                int k = m * i + j;
                if ((w & (1 << k)) != 0) {
                    cur = cur * 10 + mp[i][j];
                } else {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        rst = max(rst, sum);
    }

    printf("%d", rst);
    return 0;
}