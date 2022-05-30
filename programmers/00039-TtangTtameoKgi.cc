#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][4];
int solution(vector<vector<int> > land) {
    int answer = 0;
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    int i = 1;
    for (i = 1; i < land.size(); ++i) {
        dp[i][0] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + land[i][0];
        dp[i][1] = max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]}) + land[i][1];
        dp[i][2] = max({dp[i - 1][1], dp[i - 1][0], dp[i - 1][3]}) + land[i][2];
        dp[i][3] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]}) + land[i][3];
    }

    i -= 1;
    answer = max({dp[i][0], dp[i][1], dp[i][2], dp[i][3]});
    return answer;
}