#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dic;
    int last_index = 1;

    // LZM 1
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        dic.insert(make_pair(string({ch}), last_index++));
    }

    while (msg.length()) {
        // LZM 2
        int length = msg.length();
        string longest_str;
        while (length) {
            longest_str = msg.substr(0, length);
            if (dic[longest_str])
                break;

            length--;
        }
        // LZM 3
        answer.push_back(dic[longest_str]);

        // LZM 4
        if (length + 1 < msg.length()) dic[msg.substr(0, length + 1)] = last_index++;
        msg.erase(msg.begin(), msg.begin() + length);
    }

    return answer;
}