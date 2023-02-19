#include <iostream>
#include <cmath>

using namespace std;

int lv[12];
int rst[10000];
int k;
int input[10000];
int ipslt;

void dfs(int idx, int l) {
    if (l + 1 == k) {
        rst[idx] = input[ipslt++];
        return;
    }

    dfs(2 * idx, l + 1);
    rst[idx] = input[ipslt++];
    dfs(2 * idx + 1, l + 1);
}

int main() {
    cin >> k;
    for (int i = 0; i < ((int)pow(2.0, (float)k)) - 1; ++i)
        cin >> input[i];

    dfs(1, 0);

    int until = 1;
    int two = 2;
    for (int i = 1; i <= ipslt; ++i) {
        cout << rst[i] << " ";
        if (i == until) {
            cout << "\n";
            until += two;
            two *= 2;
        }
    }

    return 0;
}