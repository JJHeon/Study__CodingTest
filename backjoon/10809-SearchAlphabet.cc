#include <iostream>
#include <vector>
#include <string>
using namespace std;

int HASH_ALPHABET[26];
string INPUT;
int main() {
    cin >> INPUT;

    fill_n(HASH_ALPHABET, 26, -1);

    for (auto itr = INPUT.begin(); itr != INPUT.end(); ++itr) {
        if (HASH_ALPHABET[static_cast<int>(*itr) - 97] == -1) HASH_ALPHABET[static_cast<int>(*itr) - 97] = static_cast<int>(itr - INPUT.begin());
    }

    for (int i = 0; i < 26; ++i) cout << HASH_ALPHABET[i] << " ";
    return 0;
}