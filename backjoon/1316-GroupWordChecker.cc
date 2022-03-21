#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> INPUT;
int COUNT;
int HASH_ALPHAMBET[27];

int main() {
    cin >> N;
    for (int i = 0; i != N; ++i) {
        string tmp;
        cin >> tmp;
        INPUT.push_back(tmp);
    }

    int dummy = 0;
    for (auto str : INPUT) {
        fill_n(HASH_ALPHAMBET, 27, 0);
        char current = str[0] - 96;
        for (auto ch : str) {
            char selected = ch - 96;
            if (current != selected && HASH_ALPHAMBET[selected] != 0)
                goto fail;
            else if (current != selected)
                current = selected;
            HASH_ALPHAMBET[selected]++;
        }
        COUNT++;
    fail:
        dummy = 0;
    }
    cout << COUNT;

    return 0;
}