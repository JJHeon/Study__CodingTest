#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int m;
string in;
int v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> in;

        int idx = 0;
        if (in == "add") {
            cin >> idx;
            v |= (1 << (idx - 1));
        } else if (in == "check") {
            cin >> idx;
            cout << (bool)(v & (1 << (idx - 1))) << "\n";
        } else if (in == "remove") {
            cin >> idx;
            v = v & (~(1 << (idx - 1)));
        } else if (in == "toggle") {
            cin >> idx;
            v = v ^ (1 << (idx - 1));
        } else if (in == "all") {
            v = INT32_MAX;
        } else if (in == "empty") {
            v = 0;
        }
    }

    return 0;
}