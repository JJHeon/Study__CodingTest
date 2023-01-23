#include <iostream>

using namespace std;

string s;
int main() {
    getline(cin, s);

    for (char& c : s) {
        if ('a' <= c && c <= 'z') {
            char temp = (((c - 'a') + 13) % 26) + 'a';
            c = temp;
        } else if ('A' <= c && c <= 'Z') {
            char temp = (((c - 'A') + 13) % 26) + 'A';
            c = temp;
        }
    }
    cout << s;
    return 0;
}