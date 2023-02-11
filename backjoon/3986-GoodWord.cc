#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    string s;
    vector<char> v;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s;

        v.clear();
        for (char c : s) {
            if (v.size() > 0 && v.back() == c) {
                v.pop_back();
            } else
                v.push_back(c);
        }
        if (v.size() == 0) result++;
    }

    cout << result;
    return 0;
}