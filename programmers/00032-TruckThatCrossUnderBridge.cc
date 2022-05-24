#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<pair<int, int>> q;
    int time = 0;
    int load = 0;
    int index = 0;
    while (index != truck_weights.size()) {
        time++;

        if (q.size() > 0 && time - q.front().second >= bridge_length) {
            load -= q.front().first;
            q.pop();
        }

        if (q.size() < bridge_length && load + truck_weights[index] <= weight) {
            load += truck_weights[index];
            q.push(make_pair(truck_weights[index], time));
            index++;
        }
    }

    while (q.size() > 0) {
        while (time - q.front().second != bridge_length)
            time++;
        q.pop();
    }
    answer = time;

    return answer;
}