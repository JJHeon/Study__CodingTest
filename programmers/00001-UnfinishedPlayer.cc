#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    string answer = "";
    for (const auto& s : participant) {
        m[s]++;
    }
    for (const auto& s : completion) {
        if (m.find(s) != m.end()) {
            m[s]--;
        }
    }
    for (const auto& s : participant) {
        if (m[s] > 0) {
            answer += s;
            break;
        }
    }

    return answer;
}