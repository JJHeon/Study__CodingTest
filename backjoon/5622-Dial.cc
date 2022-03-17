#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;
int NUMBER[10];
string INPUT;
int RESULT;
int GetValue(const char& target) {
    if (65 <= target && target <= 67)
        return 2;
    else if (68 <= target && target <= 70)
        return 3;
    else if (71 <= target && target <= 73)
        return 4;
    else if (74 <= target && target <= 76)
        return 5;
    else if (77 <= target && target <= 79)
        return 6;
    else if (80 <= target && target <= 83)
        return 7;
    else if (84 <= target && target <= 86)
        return 8;
    else if (87 <= target && target <= 90)
        return 9;
    else
        return -1;
}

int main() {
    cin >> INPUT;
    int i = 2;
    for_each(&NUMBER[1], &NUMBER[9] + 1, [&i](int& num) -> void {
        num = i;
        i++;
    });

    // for (int j = 1; j <= 9; j++) cout << NUMBER[j] << " ";
    // cout << "\n";

    for (const char& c : INPUT) {
        // cout << "d : " << GetValue(c) << endl;
        // cout << "k : " << NUMBER[GetValue(c)] << endl;
        RESULT += NUMBER[GetValue(c)];
    }
    // char a = 'A';
    // char b = 'Z';
    // printf("%d %d", a, b);

    cout << RESULT;
    return 0;
}