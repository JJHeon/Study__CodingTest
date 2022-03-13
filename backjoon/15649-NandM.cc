#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int N, M;
vector<int> RESULT;
vector<bool> MEMORIZE = vector<bool>(9, false);
// int RESULT[9];
// bool MEMORIZE[9];

void Solution(int count) {
    if (count == M) {
        // for (int i = 0; i < M; ++i) printf("%d ", RESULT[i]);
        for (int i = 0; i < M; ++i) cout << RESULT[i] << " ";
        printf("\n");
        //cout << endl;

        // for (auto& num : RESULT) cout << num << " ";
        // cout << endl;
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (MEMORIZE[i]) continue;

        MEMORIZE[i] = true;
        RESULT.push_back(i);
        // RESULT[count] = i;

        Solution(count + 1);

        MEMORIZE[i] = false;
        RESULT.pop_back();
        // RESULT[count] = 0;
    }
}

int main() {
    // std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();

    cin >> N >> M;
    Solution(0);

    // std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    // auto diff = end - start;
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(diff).count() << "us" << std::endl;
    return 0;
}