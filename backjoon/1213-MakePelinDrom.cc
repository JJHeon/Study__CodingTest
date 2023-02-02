#include <iostream>
#include <string>

using namespace std;

int a[200];
string s, ret;
char mid;
int flag;

int main() {
    cin >> s;
    for (auto c : s) {
        a[c]++;
    }

    for (int i = 'Z'; i >= 'A'; --i) {
        if (a[i]) {
            if (a[i] & 1) {
                flag++;
                mid = char(i);
                a[i]--;
            }
            if (flag == 2) break;
            for (int j = 0; j < a[i]; j += 2) {
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if (flag == 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    if (mid)
        ret.insert(ret.begin() + ret.size() / 2, mid);

    cout << ret << "\n";

    return 0;
}