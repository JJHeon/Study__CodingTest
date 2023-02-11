#include <iostream>
#include <string>

using namespace std;

string s;

string success = " is acceptable.\n";
string fail = " is not acceptable.\n";

bool IsMoem(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    while (true) {
        cin >> s;
        if (s == "end") break;

        bool is_include_moem = false;
        bool is_success = true;
        int moem = 0;
        int zaem = 0;
        char prev = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (IsMoem(s[i]))
                moem++, zaem = 0, is_include_moem = true;
            else
                moem = 0, zaem++;

            if (moem == 3 || zaem == 3) {
                is_success = false;
                break;
            }
            if (i >= 1 && (s[i] != 'e' && s[i] != 'o') && prev == s[i]) {
                is_success = false;
                break;
            }

            prev = s[i];
        }
        if (!is_include_moem) {
            is_success = false;
        }
        if (is_success) {
            cout << "<" + s + ">" + success;
        } else
            cout << "<" + s + ">" + fail;
    }

    return 0;
}