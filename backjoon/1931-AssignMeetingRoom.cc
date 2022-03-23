#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int RESULT;
vector<pair<int, int>> MEETING;
int main() {
    cin >> N;
    MEETING.resize(N);
    for (int i = 0; i != N; ++i) {
        int startTime = 0;
        int endTime = 0;

        cin >> startTime >> endTime;
        MEETING[i] = make_pair(startTime, endTime);
    }

    stable_sort(MEETING.begin(), MEETING.end(), [](const pair<int, int>& meetOne, const pair<int, int>& meetTwo) -> bool {
        if (meetOne.second < meetTwo.second)
            return true;
        else if (meetOne.second > meetTwo.second)
            return false;
        else {
            if (meetOne.first < meetTwo.first)
                return true;
            else
                return false;
        }
    });

    int saveEndTime = 0;
    for (auto meet : MEETING) {
        if (saveEndTime <= meet.first) {
            saveEndTime = meet.second;
            RESULT++;
        }
    }
    cout << RESULT;

    return 0;
}