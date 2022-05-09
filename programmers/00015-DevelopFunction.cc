#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int waiting_pos = 0;
    const int total_num_progresses = progresses.size();

    while (waiting_pos < total_num_progresses) {
        for (int i = 0; i < total_num_progresses; ++i) {
            if (progresses[i] < 100) progresses[i] += speeds[i];
        }

        int count_finished_work = 0;
        for (; progresses[waiting_pos] >= 100 && waiting_pos < total_num_progresses; waiting_pos++) {
            count_finished_work++;
        }
        if (count_finished_work != 0) answer.push_back(count_finished_work);
    }

    return answer;
}