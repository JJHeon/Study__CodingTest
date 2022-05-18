#include <string>
#include <vector>
#include <utility>
#include <deque>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> q;

    int index = 0;
    for (auto p : priorities)
        q.push_back(make_pair(p, index++));

    int count = 1;
    while (q.size() > 0) {
        const auto& [priority, pos] = q.front();
        bool is_highest_priority_exist = false;
        for (auto i = q.begin() + 1; i != q.end(); ++i) {
            if (priority < (*i).first) {
                q.push_back(q.front());
                q.pop_front();
                is_highest_priority_exist = true;
                break;
            }
        }

        if (!is_highest_priority_exist) {
            if (pos == location) {
                answer = count;
                break;
            }
            q.pop_front();
            count++;
        }
    }

    return answer;
}