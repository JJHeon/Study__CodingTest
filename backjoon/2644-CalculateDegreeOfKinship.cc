#include <iostream>
#include <vector>
#include <list>

using namespace std;
vector<bool> visited;
vector<list<int>> node;
int n;
int m;
int target_1;
int target_2;

bool Recursive(int count, int next) {
    if (next == target_2) {
        cout << count << "\n";
        return true;
    }

    for (auto itr = node[next].begin(); itr != node[next].end(); ++itr) {
        if (visited[*itr]) continue;

        visited[*itr] = true;
        if (Recursive(count + 1, *itr)) return true;
        visited[*itr] = false;
    }
    return false;
}

int main() {
    cin >> n >> target_1 >> target_2 >> m;
    node.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int in1, in2;
        cin >> in1 >> in2;
        node[in2].push_back(in1);
        node[in1].push_back(in2);
    }

    if (!Recursive(0, target_1)) cout << "-1\n";

    return 0;
}