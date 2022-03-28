#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> solution(int num_teams, vector<string> remote_tasks, vector<string> office_tasks, vector<string> employees) {
    vector<int> answer;
    vector<vector<int>> home_workers(11, vector<int>());
    vector<vector<int>> office_workers(11, vector<int>());

    int employees_num = 0;
    for (auto str : employees) {
        employees_num++;

        istringstream sstream(str);
        int team_num = 0;
        sstream >> team_num;

        string work;
        bool is_home_work = true;
        while (sstream >> work) {
            for (const auto& task : office_tasks) {
                if (task.find(work) != string::npos) {
                    // find officer worker
                    is_home_work = false;
                    goto OUT_DOUBLE_FOR;
                }
            }
        }
    OUT_DOUBLE_FOR:
        if (is_home_work)
            home_workers[team_num].push_back(employees_num);
        else
            office_workers[team_num].push_back(employees_num);
    }

    for (auto works : home_workers) sort(works.begin(), works.end());

    for (int team_i = 1; team_i != 11; team_i++) {
        if (office_workers[team_i].size() < 1 && home_workers[team_i].size() >= 1) {
            home_workers[team_i].erase(home_workers[team_i].begin());
        }
    }

    for (auto home_team : home_workers) {
        for (auto works : home_team) {
            if (works != 0) answer.push_back(works);
        }
    }

    return answer;
}

int main() {
    vector<string> remote = {"abc", "def", "ghi"};
    vector<string> office = {"qwe", "rty", "uio"};
    vector<string> emp = {"1 abc def", "1 qwe rty", "1 uio", "2 abc def", "2 ghi", "3 abc rty uio", "3 def", "3 rty uio"};

    auto i = solution(5, remote, office, emp);
    cout << "----" << endl;
    for (auto k : i) {
        cout << k << endl;
    }
}