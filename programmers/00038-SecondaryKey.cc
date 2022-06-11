#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <unordered_set>

using namespace std;

vector<bitset<8>> hs;
int result = 0;

void Recursive(int count, int until, int n, int next, bitset<8>& bit, vector<vector<string>>& re) {
    if (count == until) {
        for (int i = 0; i < hs.size(); ++i)
            if ((bit & hs[i]) == hs[i]) {
                return;
            }

        unordered_map<string, int> m;
        for (int row = 0; row < re.size(); ++row) {
            string t = "";
            for (int i = 0; i < n; ++i) {
                if (!bit[i]) continue;
                t += re[row][i];
            }
            m[t]++;
            if (m[t] > 1) {
                return;
            }
        }
        hs.push_back(bit);
        result++;
        return;
    }

    for (int i = next; i < n; ++i) {
        if (bit[i]) continue;

        bit[i] = true;
        Recursive(count + 1, until, n, i + 1, bit, re);

        bit[i] = false;
    }
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    const int n = relation[0].size();
    bitset<8> bit;
    for (int i = 1; i <= n; ++i)
        Recursive(0, i, n, 0, bit, relation);

    answer = result;
    return answer;
}