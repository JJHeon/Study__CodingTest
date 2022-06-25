#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    string input;
    cin >> input;

    unordered_map<char, int> table;
    vector<vector<bool>> card_set(4, vector<bool>(13, false));

    table['P'] = 0;
    table['K'] = 1;
    table['H'] = 2;
    table['T'] = 3;

    for (int i = 0; i < input.length(); i += 3) {
        int num = stoi(input.substr(i + 1, 2));
        int type = table[input[i]];
        if (card_set[type][num - 1]) {
            cout << "GRESKA";
            return 0;
        }

        card_set[type][num - 1] = true;
    }

    for (int i = 0; i < 4; ++i) {
        int count = 0;
        for (int j = 0; j < 13; ++j)
            if (card_set[i][j]) count++;
        cout << 13 - count << " ";
    }
    cout << endl;
    return 0;
}
