#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> node[52];
int input;
int d;
int root;

int dfs(int i) {
    int ret = 0;
    int child = 0;
    for (auto it : node[i]) {
        if (it == d) continue;
        ret += dfs(it);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        if (input == -1)
            root = i;
        else
            node[input].push_back(i);
    }
    cin >> d;
    if (d == root)
        cout << 0 << "\n";
    else
        cout << dfs(root) << "\n";

    return 0;
}