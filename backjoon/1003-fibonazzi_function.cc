#include <iostream>
#include <array>
#include <vector>

int T;

std::vector<int> ONE = std::vector(41, -1);
std::vector<int> ZERO = std::vector(41, -1);

int Solution() {
    // Input, // Write input process using std::cin
    std::cin >> T;

    // Default Value
    ONE[0] = 0;
    ONE[1] = 1;
    ZERO[0] = 1;
    ZERO[1] = 0;

    int test;
    // Partial Input
    for (int i = 0; i < T; ++i) {
        std::cin >> test;

        // Process
        for (int i = 2; i <= test; ++i) {
            if (ONE[i] != -1 && ZERO[i] != -1) continue;
            ONE[i] = ONE[i - 2] + ONE[i - 1];
            ZERO[i] = ZERO[i - 2] + ZERO[i - 1];
        }
        std::cout << ZERO[test] << " " << ONE[test] << std::endl;
    }

    // Result
    return 0;
}

int main() {
    Solution();

    return 0;
}
