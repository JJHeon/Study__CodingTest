#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> convert_to_int;
    unordered_map<string, int> report_count;
    vector<vector<int>> track_reported(id_list.size(), vector<int>());

    int count = 0;
    for (const auto& str : id_list)
        convert_to_int[str] = count++;

    for (const auto& str : report) {
        const int delim = str.find(' ');
        string reporter = str.substr(0, delim);
        string target = str.substr(delim + 1);

        const int pos_target = convert_to_int[target];
        const int pos_reporter = convert_to_int[reporter];
        if (track_reported[pos_target].end() == std::find(track_reported[pos_target].begin(), track_reported[pos_target].end(), pos_reporter)) {
            track_reported[pos_target].push_back(pos_reporter);
            report_count[target]++;
        }
    }

    cout << endl;
    for (auto p : report_count) {
        const auto& [name, count] = p;
        if (count >= k) {
            const int pos_target = convert_to_int[name];
            for (const auto who : track_reported[pos_target]) answer[who]++;
        }
    }

    return answer;
}