#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> node[52];
int erase[52];
int input;
int d;

void dfs(int i) {
    erase[i] = 1;
    for (auto it : node[i]) dfs(it);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        node[input + 1].push_back(i + 1);
    }
    cin >> d;

    dfs(d + 1);

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!erase[i]) {
            if (node[i].size() == 0) {
                cnt++;
                continue;
            }
            bool flag = true;
            for (auto it : node[i]) {
                if (!erase[it]) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}