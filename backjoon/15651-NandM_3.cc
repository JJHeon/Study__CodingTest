#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> RESULT;

void Solution(int count) {
    if (count == M) {
        for (auto& num : RESULT) cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        RESULT.push_back(i);
        Solution(count + 1);
        RESULT.pop_back();
    }
}

int main() {
    cin >> N >> M;

    Solution(0);

    return 0;
}