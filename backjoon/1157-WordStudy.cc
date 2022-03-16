#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;
int HASH_ALPHABET[26];
string INPUT;
int main() {
    cin >> INPUT;

    for (const char c : INPUT) {
        int pos = tolower(c) - 97;
        HASH_ALPHABET[pos]++;
    }

    int result = -1;
    int result_pos = -1;
    for (int i = 0; i != 26; ++i)
        if (HASH_ALPHABET[i] > result) {
            result = HASH_ALPHABET[i];
            result_pos = i;
        }

    int count = 0;
    for (int j = 0; j != 26; ++j)
        if (HASH_ALPHABET[j] == result) count++;

    if (count > 1)
        cout << '?';
    else
        printf("%c", toupper(result_pos + 97));

    return 0;
}