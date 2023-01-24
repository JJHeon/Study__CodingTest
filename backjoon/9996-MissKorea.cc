#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string pattern;

vector<string> split(string s, string deli) {
    vector<string> rst;
    string token = "";
    size_t pos = 0;
    while ((pos = s.find(deli)) != string::npos) {
        token = s.substr(0, pos);
        rst.push_back(token);
        s.erase(0, pos + deli.length());
    }

    rst.push_back(s);
    return rst;
}

int main() {
    cin >> n;
    cin >> pattern;

    auto condition = split(pattern, "*");

    vector<string> rst;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(s.length() < condition[0].length() + condition[1].length()){
            rst.push_back("NE");
            continue;
        }
        
        string prefix = s.substr(0, condition[0].length());
        if (prefix != condition[0]) {
            rst.push_back("NE");
            continue;
        }


        string suffix = s.substr(s.length() - condition[1].length(), condition[1].length());
        if (suffix != condition[1]) {
            rst.push_back("NE");
            continue;
        }


        rst.push_back("DA");
    }

    for (string s : rst)
        cout << s << "\n";

    return 0;
}