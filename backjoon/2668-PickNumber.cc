#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int N;
vector<int> T;
int RES;

set<int> s1;
set<int> s2;
vector<bool> V;
set<int> RES_V;

void DFS(int parent) {
    if (V[parent]) return;

    V[parent] = true;
    s1.insert(parent);
    s2.insert(T[parent]);

    DFS(T[parent]);
}

int main() {
    cin >> N;

    T.resize(N + 1, 0);
    V.resize(N + 1, false);

    for (int i = 1; i <= N; ++i) cin >> T[i];

    for (int i = 1; i <= N; ++i) {
        DFS(i);

        if (s1 == s2) {
            for (auto i : s1) {
                if (RES_V.find(i) == RES_V.end()) {
                    RES_V.insert(i);
                    RES += 1;
                }
            }
        }

        s1.clear();
        s2.clear();
        fill(V.begin(), V.end(), false);
    }

    cout << RES << endl;
    for (auto i : RES_V) cout << i << endl;

    return 0;
}