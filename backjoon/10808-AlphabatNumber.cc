#include <iostream>
#include <string>

using namespace std;

int a[26];
string word;
int main() {
    cin >> word;
    for (char c : word) {
        a[c - 97]++;
    }

    for (int i = 0; i < 26; ++i) cout << a[i] << " ";
    return 0;
}
