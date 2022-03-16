#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int T;
vector<pair<int, string>> INPUT;

int main() {
    // Input
    cin >> T;
    for (int i = 0; i != T; ++i) {
        int r;
        string s;

        cin >> r >> s;
        INPUT.push_back(make_pair(r, s));
    }

    for (auto target : INPUT) {
        int r = target.first;
        string s = target.second;

        for (const char& c : s) {
            for (int i = 0; i != r; ++i) cout << c;
        }
        cout << "\n";
    }

    return 0;
}