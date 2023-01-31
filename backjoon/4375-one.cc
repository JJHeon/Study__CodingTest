#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int n;
int main() {
    // string s;
    // getline(cin, s);

    // stringstream ss(s);
    // while (ss >> n) {
    while (cin >> n) {
        if (cin.eof()) break;
        int cnt = 1;
        int dust = 1 % n;
        while (true) {
            // cout << dust << "\n";
            if (dust == 0) break;
            dust = (dust * 10 + 1) % n;
            cnt++;
        }

        // cout << "resut\n";
        cout << cnt << "\n";
    }

    return 0;
}