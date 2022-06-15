#include <string>
#include <vector>
#include <cstdint>

using namespace std;

void Recursive(int count, vector<int>& info, int ryan, int apich, int next, vector<int>& score, vector<int>& answer, int n) {
    static int max = INT32_MIN;
    if (count == info.size()) {
        if (ryan > apich && (ryan - apich) >= max) {
            int sum = 0;
            for (int i = 0; i < score.size(); ++i) sum += score[i];
            if (sum != n) return;
            if((ryan - apich) == max){
                int current_sum = 0;
                int previous_sum = 0;
                for (int i = 10; i >= 0; --i) {
                    current_sum += score[i];
                    previous_sum += answer[i];
                    if (current_sum < previous_sum) return;
                }
            }


            answer = score;
            max = ryan - apich;
        }
        return;
    }

    for (int i = next; i >= 0; --i) {
        score.push_back(i);
        if (i > info[count])
            Recursive(count + 1, info, ryan + (10 - count), apich, next - i, score, answer, n);
        else if(info[count] != 0 && i <= info[count])
            Recursive(count + 1, info, ryan, apich + (10 - count), next - i, score, answer, n);
        else                                       
            Recursive(count + 1, info, ryan, apich, next - i, score, answer, n);
        score.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> score;
    Recursive(0, info, 0, 0, n, score, answer, n);
    if (answer.size() == 0) answer.push_back(-1);
    return answer;
}