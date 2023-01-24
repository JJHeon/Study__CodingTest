#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<string> codes(100004);
map<string, int> names;
string input;
vector<string> rst;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> input;
        names[input] = i;
        codes[i] = input;
    }
    for (int i = 1; i <= m; ++i){
        cin >> input;
        if (('a' <= input[0] && input[0] <= 'z') || ('A' <= input[0] && input[0] <= 'Z')){
            rst.push_back(to_string(names[input]));
        }
        else if('0' <= input[0] && input[0] <= '9')
            rst.push_back(codes[atoi(input.c_str())]);
    }

    for (string s : rst) cout << s << "\n";
    return 0;
}