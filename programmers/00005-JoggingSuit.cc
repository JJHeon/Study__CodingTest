#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n, 1);
    for (const auto& p : lost)
        students.at(p - 1) -= 1;
    for (const auto& p : reserve)
        students.at(p - 1) += 1;

    for (int i = 0; i < n; ++i) {
        if (students[i] == 0) {
            int forward = i - 1;
            int backward = i + 1;
            if (forward > 0 && students[forward] == 2) {
                students[forward]--;
                students[i]++;
                answer++;
                continue;
            } else if (backward < n && students[backward] == 2) {
                students[backward]--;
                students[i]++;
                answer++;
                continue;
            }
        } else
            answer++;
    }
    return answer;
}