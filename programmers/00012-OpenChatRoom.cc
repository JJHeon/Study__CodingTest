#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

using Chat = struct Chat {
    string command;
    string uid;
    string name;
    Chat(string command, string uid, string name) : command(command), uid(uid), name(name) {}
};

vector<string>
solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> command_buf;
    map<string, string> m;

    for (auto str : record) {
        istringstream s(str);
        string command;
        string uid;
        string name;

        s >> command >> uid;
        if (command == "Leave") {
            name = m[uid];
        } else
            s >> name;

        m[uid] = name;
        if (command != "Change") {
            command_buf.push_back(make_pair(command, uid));
        }
    }

    for (auto cht : command_buf) {
        auto& [command, uid] = cht;
        string sentence = m[uid];
        if (command == "Enter")
            sentence += "님이 들어왔습니다.";
        else if (command == "Leave")
            sentence += "님이 나갔습니다.";

        answer.push_back(sentence);
    }

    return answer;
}