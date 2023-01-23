#include <iostream>

using namespace std;
int a[26];
string s;
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        a[s[0] - 'a'] += 1;
    }
    bool is_success = false;
    for (int i = 0; i < 26; ++i) {
        if (a[i] >= 5) {
            cout << static_cast<char>(('a' + i));
            is_success = true;
        }
    }
    if (!is_success) cout << "PREDAJA";
    return 0;
}