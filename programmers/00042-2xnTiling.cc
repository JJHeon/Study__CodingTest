#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[2][60001];

int solution(int n) {
    int answer = 0;

    dp[0][1] = 1;
    dp[1][1] = 0;
    dp[0][2] = 1;
    dp[1][2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % 1000000007;
        dp[1][i] = (dp[0][i - 2] + dp[1][i - 2]) % 1000000007;
    }

    answer = (dp[0][n] + dp[1][n]) % 1000000007;
    return answer;
}