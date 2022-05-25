#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    unordered_map<string, string> hash;
    map<string, int> gather_minute;

    //입 & 출차 분 수집
    for (string str : records) {
        string time;
        string number;
        string detail;
        stringstream in(str);

        in >> time >> number >> detail;

        auto it = hash.find(number);
        if (it == hash.end()) {
            hash.insert(make_pair(number, time));
        } else {
            int in_hour = stoi(hash[number].substr(0, 2));
            int in_minute = stoi(hash[number].substr(3, 2));
            int out_hour = stoi(time.substr(0, 2));
            int out_minute = stoi(time.substr(3, 2));

            int total_minute = (out_hour - in_hour) * 60 + (out_minute - in_minute);
            gather_minute[number] += total_minute;

            hash.erase(it);
        }
    }

    // 출차 안한 차들 마저 수집
    for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
        int in_hour = stoi(itr->second.substr(0, 2));
        int in_minute = stoi(itr->second.substr(3, 2));

        int total_minute = (23 - in_hour) * 60 + (59 - in_minute);
        gather_minute[itr->first] += total_minute;
    }

    for (auto& p : gather_minute) {
        int time = p.second - fees[0];
        if (time <= 0) {
            answer.push_back(fees[1]);
            continue;
        }

        int total_fees = fees[1];
        int r = time % fees[2];
        if (fees[1] != 1 && r != 0)
            total_fees += fees[3];
        total_fees += (time / fees[2] * fees[3]);
        answer.push_back(total_fees);
    }

    return answer;
}