#include <string>
#include <vector>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<string> logs) {
    int answer = -1;

    string context = R"(team_name :\s[a-zA-Z]+\sapplication_name\s:\s[a-zA-Z]+ error_level\s:\s[a-zA-Z]+\smessage\s:\s[a-zA-Z]+)";
    regex re(context);
    std::smatch match;
    int count = 0;
    for (const auto& str : logs) {
        if (regex_match(str, match, re)) {
            // cout << match[0].str() << endl;
            if (match[0].str().length() <= 100) count++;
        }
    }
    answer = logs.size() - count;
    return answer;
}