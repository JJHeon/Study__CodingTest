#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

int n, k;
int mp[2][500002];
int t = 1;

void sol() {
    queue<int> q;
    mp[0][n] = 1;

    q.push(n);

    if (n == k) {
        cout << "0\n";
        return;
    }

    while (q.size()) {
        k += t;

        if (k > 500000) {
            cout << "-1\n";
            return;
        }

        if (mp[t % 2][k]) {
            cout << t << "\n";
            return;
        }

        int qs = q.size();
        for (int i = 0; i < qs; i++) {
            int x = q.front();
            q.pop();

            for (auto nn : {x + 1, x - 1, 2 * x}) {
                if (nn < 0 || 500000 < nn) continue;
                if (mp[t % 2][nn]) continue;

                mp[t % 2][nn] = mp[(t + 1) % 2][x] + 1;

                if (nn == k) {
                    cout << t << "\n";

                    return;
                }
                q.push(nn);
            }
        }
        t++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    sol();

    return 0;
}