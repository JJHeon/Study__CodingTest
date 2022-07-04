#include <string>
#include <vector>
#include <iostream>

using namespace std;
void Recursive(int count, int n, vector<vector<int>>& map, int& answer) {
    if (count == n) {
        answer++;
        // Debug
        //  cout << answer << endl;
        //  for (int i = 0; i < n; ++i){
        //      for (int j = 0; j < n; ++j){
        //          cout << map[i][j] << " ";
        //      }
        //      cout << "\n";
        //  }
        return;
    }

    for (int j = 0; j < n; ++j) {
        int i = count;
        if (map[i][j] == 1) continue;
        for (int k = j + 1; k < n; ++k)
            if (map[i][k]) goto OUT_DOUBLE_FOR;
        for (int k = j - 1; k >= 0; --k)
            if (map[i][k]) goto OUT_DOUBLE_FOR;
        for (int k = i - 1; k >= 0; --k)
            if (map[k][j]) goto OUT_DOUBLE_FOR;
        for (int k = i + 1; k < n; ++k)
            if (map[k][j]) goto OUT_DOUBLE_FOR;
        for (int k = 1; (i + k < n && j + k < n); ++k)
            if (map[i + k][j + k]) goto OUT_DOUBLE_FOR;
        for (int k = 1; (i - k >= 0 && j + k < n); ++k)
            if (map[i - k][j + k]) goto OUT_DOUBLE_FOR;
        for (int k = 1; (i - k >= 0 && j - k >= 0); ++k)
            if (map[i - k][j - k]) goto OUT_DOUBLE_FOR;
        for (int k = 1; (i + k < n && j - k >= 0); ++k)
            if (map[i + k][j - k]) goto OUT_DOUBLE_FOR;

        map[i][j] = 1;
        Recursive(count + 1, n, map, answer);
        map[i][j] = 0;

    OUT_DOUBLE_FOR:
        continue;
    }
}

int solution(int n) {
    int answer = 0;
    vector<vector<int>> map(n, vector<int>(n, 0));
    Recursive(0, n, map, answer);
    return answer;
}