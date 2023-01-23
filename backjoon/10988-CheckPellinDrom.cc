#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int main() {
    cin >> s;

    int mid = s.size() / 2;
    int lst = s.size() - 1;
    for (int i = 0; i <= mid; ++i) {
        if(s[i] != s[lst - i]){
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";
    return 0;
}