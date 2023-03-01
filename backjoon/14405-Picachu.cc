#include <iostream>

#include <string>

using namespace std;

string s;

int main() {
    cin >> s;
    bool suc = true;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'p' && s.substr(i, 2) == "pi")
            i += 1;

        else if (s[i] == 'k' && s.substr(i, 2) == "ka")
            i += 1;

        else if (s[i] == 'c' && s.substr(i, 3) == "chu")
            i += 2;

        else {
            suc = false;

            break;
        }
    }

    if (suc)
        cout << "YES";

    else
        cout << "NO";

    return 0;
}