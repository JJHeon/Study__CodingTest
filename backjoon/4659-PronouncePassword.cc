#include <iostream>
#include <string>

using namespace std;

char cn1[5] = {'a', 'e', 'i', 'o', 'u'};
char cn2[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
int a[200];
string s;
string fail = " is not acceptable.";
string success = " is acceptable.";
int sum;
void sol() {
    // condition 1
    fill(&a[0], &a[0] + 200, 0);
    for (int i = 0; i < s.length(); ++i)
        a[s[i]]++;

    bool cnd = false;
    for (int i = 0; i < 5; ++i)
        if (a[cn1[i]]) {
            cnd = true;
            break;
        }
    if (!cnd) {
        cout << "<" + s + ">" + fail;
        return;
    }

    // condition 2
    if (s.length() > 2) {
        for (int i = 0; i < s.length() - 2; ++i) {
            fill(&a[0], &a[0] + 200, 0);
            a[s[i]]++;
            a[s[i + 1]]++;
            a[s[i + 2]]++;

            sum = 0;
            for (int j = 0; j < 5; ++j) sum += a[cn1[j]];
            if (sum == 3) {
                cout << "<" + s + ">" + fail;
                return;
            }

            sum = 0;
            for (int z = 0; z < 21; ++z) sum += a[cn2[z]];
            if (sum == 3) {
                cout << "<" + s + ">" + fail;
                return;
            }
        }
    }

    for (int i = 0; s.length() > 1 && i < s.length() - 1; ++i) {
        if ((s[i] != 'e' && s[i] != 'o') &&
            (s[i] == s[i + 1])) {
            cout << "<" + s + ">" + fail;
            return;
        }
    }

    cout << "<" + s + ">" + success;
}

int main() {
    while (true) {
        cin >> s;
        if (s == "end") break;
        sol();
        cout << "\n";
    }

    return 0;
}