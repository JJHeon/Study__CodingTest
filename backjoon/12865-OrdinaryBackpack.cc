#include <iostream>
#include <cstdint>
#include <algorithm>

using namespace std;

using WV = struct {
    int weight;
    int value;
};

int MAP[101][100001];
WV IN[101];
int N;
int K;
int RES = INT32_MIN;

int Solution() {
    // Input, // Write input process using std::cin
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> IN[i].weight >> IN[i].value;

    // Process
    for (int i = 1; i <= N; ++i) {
        // 1-1
        for (int j = 0; j <= K; ++j) {
            // 1-2

            int possibleWeight = j - IN[i].weight;
            int sumValue = 0;
            if (possibleWeight >= 0) sumValue = IN[i].value + MAP[i - 1][possibleWeight];

            MAP[i][j] = max(MAP[i - 1][j], sumValue);
        }
    }

    // Result
    cout << MAP[N][K] << endl;
    return 0;
}

int main() {
    Solution();

    return 0;
}
