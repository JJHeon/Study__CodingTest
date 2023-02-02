#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m, j;
vector<int> apple;
int map[12];
int dx[2] = {-1, 1};
int rst;
int main() {
    cin >> n >> m >> j;

    int input;
    for (int i = 0; i < j; ++i) {
        cin >> input;
        apple.push_back(input);
    }

    queue<int> q;
    for (int i = 1; i <= m; ++i) {
        q.push(i);
        map[i] = 1;
    }
    int base = 1;
    for (auto ai : apple) {
        // right
        for (int i = base + 1; i <= n; ++i)
            if (map[i] == 0) map[i] = map[i - 1] + 1;
        // left
        for (int i = base - 1; i >= 1; --i)
            if (map[i] == 0) map[i] = map[i + 1] + 1;

        // // debug
        // for (int i = 1; i <= n; ++i) {
        //     cout << map[i] << " ";
        // }
        // cout << "\n";

        // value
        rst += (map[ai] - 1);

        // reset
        if (base <= ai && ai <= base + (m - 1)) {
            for (int i = 1; i <= n; ++i)
                if (map[i] != 1) map[i] = 0;
        } else if (ai < base) {
            fill(&map[0], &map[0] + 12, 0);
            for (int i = 0; i < m; ++i) map[ai + i] = 1;
            base = ai;
        } else if (base + (m - 1) < ai) {
            fill(&map[0], &map[0] + 12, 0);
            for (int i = 0; i < m; ++i) map[ai - i] = 1;
            base = ai - (m - 1);
        }
    }
    cout << rst << "\n";
}