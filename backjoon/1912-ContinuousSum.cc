#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int RES = INT32_MIN;
int N;
int GET_INPUT[100001];
int MAP[100001];

int Solution() {
    // Input, // Write input process using std::cin
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> MAP[i];

    // Process

    if (MAP[1] > RES) RES = MAP[1];

    for (int i = 2; i <= N; ++i) {
        if (MAP[i - 1] > 0 && MAP[i - 1] + MAP[i] > 0) MAP[i] = MAP[i - 1] + MAP[i];
        if (MAP[i] > RES) RES = MAP[i];
    }

    // Result
    cout << RES;
    return 0;
}

int main() {
    Solution();

    return 0;
}
