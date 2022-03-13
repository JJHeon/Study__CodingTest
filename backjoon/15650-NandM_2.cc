#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> RESULT;

void Solution(int next, int count) {
    if (count == M) {
        for (auto& num : RESULT) cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = next; i <= N; ++i) {
        RESULT.push_back(i);
        Solution(i + 1, count + 1);
        RESULT.pop_back();
    }
}

int main() {
    cin >> N >> M;

    Solution(1, 0);

    return 0;
}