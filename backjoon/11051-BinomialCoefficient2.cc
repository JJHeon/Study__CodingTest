#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    table[0][0] = 1;
    table[1][0] = 1;
    table[1][1] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= i; ++j){
            if (j - 1 < 0) table[i][j] = table[i - 1][j] % 10007;
            else table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % 10007;
        }
    }
    cout << table[n][k] << "\n";

    return 0;
}